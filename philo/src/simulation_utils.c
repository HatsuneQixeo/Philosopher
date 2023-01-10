/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

int	philo_alive(t_philo *philo, long current)
{
	return (current <= philo->info.last_meal + philo->table->countdown);
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

	mutex_report(pthread_mutex_lock, &philo->table->mutex_log);
	if (stat_get(&philo->table->stat_end) != DIED)
		printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	if (action == death)
		stat_set(&philo->table->stat_end, DIED);
	mutex_report(pthread_mutex_unlock, &philo->table->mutex_log);
}

void	philo_do(t_philo *philo, int time)
{
	long	start;

	start = philo_time(philo->table);
	while (philo_time(philo->table) - start < time)
		usleep(WAIT);
}
