/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:28:14 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 02:28:16 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

long	philo_time(t_table *table)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - table->start.tv_sec) * MS)
		+ ((time.tv_usec - table->start.tv_usec) / MS));
}

void	philo_log(t_philo *philo, const char *action)
{
	static pthread_mutex_t	log_mutex = PTHREAD_MUTEX_INITIALIZER;

	mutex_report(pthread_mutex_lock, &log_mutex);
	if (stat_get(&philo->table->end) != DIED)
		printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	mutex_report(pthread_mutex_unlock, &log_mutex);
}

static int	philo_status(t_philo *philo, long current)
{
	if (current <= philo->info.last_meal + philo->table->countdown)
		return (1);
	philo_log(philo, DEATH);
	stat_set(&philo->table->end, DIED);
	return (0);
}

void	philo_do(t_philo *philo, int time)
{
	long	wait;
	long	longing;

	wait = philo_time(philo->table);
	longing = wait;
	while (longing - wait < time)
	{
		if (!philo_status(philo, longing))
			break ;
		usleep(WAIT);
		longing = philo_time(philo->table);
	}
}

void	philo_think(t_philo *philo)
{
	while (!stat_get(philo->lfork) || !stat_get(philo->rfork))
	{
		if (!philo_status(philo, philo_time(philo->table)))
			break ;
		usleep(WAIT);
	}
}
