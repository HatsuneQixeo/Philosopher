/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:44 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

int	philo_isalive(t_philo *philo, long current)
{
	return (current - stat_get(&philo->info.stat_meal)
		<= philo->table->countdown);
}

long	philo_time(t_table *table)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - table->time_start.tv_sec) * MS)
		+ ((time.tv_usec - table->time_start.tv_usec) / MS));
}

void	philo_log(t_philo *philo, const char *action)
{
	static const char	*death = DEATH;

	semaphore_report(sem_wait, philo->table->sem_log);
	printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	if (action != death)
		semaphore_report(sem_post, philo->table->sem_log);
}

void	philo_do(t_philo *philo, int time)
{
	long	start;

	start = philo_time(philo->table);
	while (philo_time(philo->table) - start < time)
		usleep(WAIT);
}
