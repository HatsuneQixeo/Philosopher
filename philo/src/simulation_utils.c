/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 13:58:22 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

long	philo_time(t_table *table)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - table->time_start.tv_sec) * MS)
		+ ((time.tv_usec - table->time_start.tv_usec) / MS));
}

void	philo_log(t_philo *philo, const char *action)
{
	mutex_report(pthread_mutex_lock, &philo->table->mutex_log);
	if (stat_get(&philo->table->stat_end) != DIED)
		printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	mutex_report(pthread_mutex_unlock, &philo->table->mutex_log);
}

static int	philo_alive(t_philo *philo, long current)
{
	return (current <= philo->info.last_meal + philo->table->countdown);
}

void	philo_do(t_philo *philo, int time)
{
	long	start;
	long	pass;

	start = philo_time(philo->table);
	pass = start;
	while (pass - start < time)
	{
		if (!philo_alive(philo, pass))
		{
			philo_log(philo, DEATH);
			stat_set(&philo->table->stat_end, DIED);
			break ;
		}
		usleep(WAIT);
		pass = philo_time(philo->table);
	}
}

void	philo_think(t_philo *philo)
{
	while (stat_get(philo->lfork) == TAKEN || stat_get(philo->rfork) == TAKEN)
	{
		if (!philo_alive(philo, philo_time(philo->table)))
		{
			philo_log(philo, DEATH);
			stat_set(&philo->table->stat_end, DIED);
			break ;
		}
		usleep(WAIT);
	}
}
