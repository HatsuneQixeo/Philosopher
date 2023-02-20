/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:08:12 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

static void	iter_monitor(int i, t_table *table, void *ptr_philo, void *ptr_null)
{
	t_philo	*philo;

	philo = ((t_philo *)ptr_philo) + i;
	if (philo_alive(philo, *(long *)ptr_null))
		return ;
	philo_log(philo, DEATH);
	(void)ptr_null;
	(void)table;
}

static void	*philo_monitoring(void *ptr_strphilo)
{
	t_philo	*str_philo;
	long	time;

	str_philo = ptr_strphilo;
	while (stat_get(&str_philo->table->stat_end) != DIED)
	{
		time = philo_time(str_philo->table);
		philo_for(iter_monitor, str_philo->table, str_philo, &time);
		usleep(500);
	}
	return (NULL);
}

void	philo_monitor_thread(t_philo *str_philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, philo_monitoring, str_philo);
	pthread_detach(thread);
}
