/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/07 18:59:45 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"
#include <signal.h>

static void	philo_getforks(t_philo *philo)
{
	sem_wait(philo->table->forks);
	philo_log(philo, GETFORK);
	sem_wait(philo->table->forks);
	philo_log(philo, GETFORK);
}

static void	philo_putforks(t_philo *philo)
{
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
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

// Create a thread for each philosother and kill everyone when someone died?
// Probably need to detach the thread for convenience too
void	*philo_monitor(void *ptr_philo)
{
	t_philo	*philo;

	philo = ptr_philo;
	while (philo_alive(philo, philo_time(philo->table)))
		usleep(MS);
	philo_log(philo, DEATH);
	kill(0, SIGTERM);
	return (NULL);
}

void	ft_simulation(t_philo *philo)
{
	pthread_t	monitor;

	philo->info.last_meal = philo_time(philo->table);
	pthread_create(&monitor, NULL, philo_monitor, philo);
	pthread_detach(monitor);
	while (1)
	{
		philo_eat(philo);
		philo_log(philo, SLEEP);
		if (philo->info.eaten >= philo->table->stat_end.status)
			break ;
		philo_do(philo, philo->table->sleep_duration);
		philo_log(philo, THINK);
	}
	exit(0);
}
