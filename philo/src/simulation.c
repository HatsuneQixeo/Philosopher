/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 13:58:22 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

static void	philo_getforks(t_philo *philo)
{
	philo_think(philo);
	stat_set(philo->lfork, TAKEN);
	stat_set(philo->rfork, TAKEN);
	philo_log(philo, GETFORK);
	philo_log(philo, GETFORK);
}

static void	philo_putforks(t_philo *philo)
{
	stat_set(philo->lfork, AVAILABLE);
	stat_set(philo->rfork, AVAILABLE);
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

void	*ft_simulation(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	philo->info.last_meal = philo_time(philo->table);
	if (philo->info.id % 2)
		philo_do(philo, 1);
	while (philo->info.eaten < stat_get(&philo->table->stat_end))
	{
		philo_eat(philo);
		if (philo->info.eaten >= stat_get(&philo->table->stat_end))
			break ;
		philo_log(philo, SLEEP);
		philo_do(philo, philo->table->sleep_duration);
		philo_log(philo, THINK);
	}
	return (NULL);
}
