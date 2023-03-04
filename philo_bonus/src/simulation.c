/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:42 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

static void	philo_getforks(t_philo *philo)
{
	semaphore_report(sem_wait, philo->table->forks);
	philo_log(philo, GETFORK);
	semaphore_report(sem_wait, philo->table->forks);
	philo_log(philo, GETFORK);
}

static void	philo_putforks(t_philo *philo)
{
	semaphore_report(sem_post, philo->table->forks);
	semaphore_report(sem_post, philo->table->forks);
}

static void	philo_eat(t_philo *philo)
{
	philo_getforks(philo);
	time_set(&philo->info.time_lastmeal);
	philo_log(philo, EAT);
	philo_do(philo, philo->table->meal_duration);
	philo->info.eaten += philo->table->loop_end;
	philo_putforks(philo);
}

static void	*philo_monitor(void *ptr_philo)
{
	t_philo	*philo;

	philo = ptr_philo;
	while (philo_isalive(philo, philo_time(philo->table)))
		usleep(MS / 2);
	philo_log(philo, DEATH);
	exit(1);
	return (NULL);
}

void	philo_simulation(t_philo *philo)
{
	pthread_t	monitor;

	time_set(&philo->info.time_lastmeal);
	pthread_create(&monitor, NULL, philo_monitor, philo);
	pthread_detach(monitor);
	while (1)
	{
		philo_eat(philo);
		philo_log(philo, SLEEP);
		if (philo->info.eaten >= philo->table->meal_end)
			break ;
		philo_do(philo, philo->table->sleep_duration);
		philo_log(philo, THINK);
	}
	semaphore_report(sem_post, philo->table->sem_end);
	exit(0);
}
