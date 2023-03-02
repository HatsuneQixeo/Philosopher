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

static int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

int	philo_isalive(t_philo *philo, time_t current)
{
	const t_table	*table = philo->table;

	return (current - time_get(&philo->info.time_lastmeal, table->time_start)
		<= table->countdown);
}

time_t	philo_time(t_table *table)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - table->time_start.tv_sec) * MS)
		+ ((time.tv_usec - table->time_start.tv_usec) / MS));
}

void	philo_log(t_philo *philo, const char *action)
{
	semaphore_report(sem_wait, philo->table->sem_log);
	printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	if (ft_strcmp(action, DEATH))
		semaphore_report(sem_post, philo->table->sem_log);
}

void	philo_do(t_philo *philo, int time)
{
	time_t	start;

	start = philo_time(philo->table);
	while (philo_time(philo->table) - start < time)
		usleep(WAIT);
}
