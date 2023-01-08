/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/07 18:59:45 by hqixeo           ###   ########.fr       */
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
	static const char	*death = DEATH;

	if (sem_wait(philo->table->sem_log) == -1)
		perror("SEM_WAIT");
	printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
	if (action != death && sem_post(philo->table->sem_log) == -1)
		perror("SEM_POST");
	// fflush(stdout);
}

// void	philo_log(t_philo *philo, const char *action)
// {
// 	static const char	*death = DEATH;

// 	if (sem_wait(philo->table->sem_log) == -1)
// 		perror("SEM_WAIT");
// 	if (action == death)
// 		printf("%ld %d %s\n", philo_time(philo->table), philo->info.id, action);
// 	if (sem_post(philo->table->sem_log) == -1)
// 		perror("SEM_POST");
// 	// fflush(stdout);
// }

int	philo_alive(t_philo *philo, long current)
{
	return (current <= philo->info.last_meal + philo->table->countdown);
}

void	philo_do(t_philo *philo, int time)
{
	long	start;

	start = philo_time(philo->table);
	while (philo_time(philo->table) - start < time)
		usleep(WAIT);
}
