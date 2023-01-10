/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

void	philo_for(t_iter ft_iter, t_table *table, void *arg1, void *arg2)
{
	int	i;

	i = -1;
	while (++i < table->member)
		ft_iter(i, table, arg1, arg2);
}

void	philosopher(t_table table)
{
	pthread_t		*str_thread;
	pthread_mutex_t	*str_fork;
	t_philo			*str_philo;

	if (table.member == 1)
		return ((void)philo_justdie(&table));
	str_fork = malloc(table.member * sizeof(pthread_mutex_t));
	str_philo = malloc(table.member * sizeof(t_philo));
	str_thread = malloc(table.member * sizeof(pthread_t));
	philo_for(iter_init_fork, &table, str_fork, NULL);
	philo_for(iter_init_philo, &table, str_philo, str_fork);
	philo_for(iter_batch_odd, &table, str_thread, str_philo);
	usleep(100);
	philo_for(iter_batch_even, &table, str_thread, str_philo);
	philo_monitor_thread(str_philo);
	philo_for(iter_jointhread, &table, str_thread, NULL);
	philo_for(iter_clean, &table, str_fork, NULL);
	free(str_thread);
	free(str_fork);
	free(str_philo);
	mutex_report(pthread_mutex_destroy, &table.mutex_log);
	mutex_report(pthread_mutex_destroy, &table.stat_end.mutex);
}
