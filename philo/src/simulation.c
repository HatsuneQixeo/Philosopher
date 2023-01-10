/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

static void	philo_getforks(t_philo *philo)
{
	mutex_report(pthread_mutex_lock, philo->lfork);
	philo_log(philo, GETFORK);
	mutex_report(pthread_mutex_lock, philo->rfork);
	philo_log(philo, GETFORK);
}

static void	philo_putforks(t_philo *philo)
{
	mutex_report(pthread_mutex_unlock, philo->lfork);
	mutex_report(pthread_mutex_unlock, philo->rfork);
}

static void	philo_eat(t_philo *philo)
{
	philo_getforks(philo);
	philo->info.last_meal = philo_time(philo->table);
	philo_log(philo, EAT);
	philo_do(philo, philo->table->meal_duration);
	philo->table->loop(&philo->info.eaten);
	philo_putforks(philo);
}

void	*philo_simulation(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	philo->info.last_meal = philo_time(philo->table);
	while (philo->info.eaten < stat_get(&philo->table->stat_end))
	{
		philo_eat(philo);
		philo_log(philo, SLEEP);
		if (philo->info.eaten >= stat_get(&philo->table->stat_end))
			break ;
		philo_do(philo, philo->table->sleep_duration);
		philo_log(philo, THINK);
	}
	return (NULL);
}

void	philo_justdie(t_table *table)
{
	t_philo	philo;

	philo.info = (t_info){1, 0, 0};
	philo.table = table;
	philo_log(&philo, GETFORK);
	philo_do(&philo, table->countdown + 1);
	philo_log(&philo, DEATH);
	mutex_report(pthread_mutex_destroy, &table->mutex_log);
	mutex_report(pthread_mutex_destroy, &table->stat_end.mutex);
}
