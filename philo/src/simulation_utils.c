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

static int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	philo_alive(t_philo *philo, long current)
{
	return (current
		<= (stat_get(&philo->info.stat_meal) + philo->table->countdown));
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
	mutex_report(pthread_mutex_lock, &philo->table->mutex_log);
	if (stat_get(&philo->table->stat_end) != DIED)
		printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	if (!ft_strcmp(action, DEATH))
		stat_set(&philo->table->stat_end, DIED);
	mutex_report(pthread_mutex_unlock, &philo->table->mutex_log);
}

void	philo_do(t_philo *philo, int time)
{
	long	start;

	if (stat_get(&philo->table->stat_end) == DIED)
		return ;
	start = philo_time(philo->table);
	while (philo_time(philo->table) - start < time)
		usleep(WAIT);
}
