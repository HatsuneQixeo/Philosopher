/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_for_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

void	iter_init_fork(int i, t_table *table, void *ptr_forks, void *ptr_null)
{
	pthread_mutex_t	*fork;

	fork = ptr_forks;
	mutex_report(default_mutex_init, fork + i);
	(void)table;
	(void)ptr_null;
}

void	iter_init_philo(int i, t_table *table, void *ptr_philo, void *ptr_forks)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;

	philo = ptr_philo;
	fork = ptr_forks;
	philo[i] = (t_philo){default_info_init(i + 1), table,
		fork + i, fork + ((i + 1) % table->member)};
}

void	iter_jointhread(int i, t_table *table, void *ptr_thread, void *ptr_null)
{
	pthread_t	*thread;

	thread = ptr_thread;
	pthread_join(thread[i], NULL);
	(void)table;
	(void)ptr_null;
}

void	iter_clean(int i, t_table *table, void *ptr_philo, void *ptr_null)
{
	t_philo			*philo;

	philo = ptr_philo;
	mutex_report(pthread_mutex_destroy, philo[i].lfork);
	mutex_report(pthread_mutex_destroy, &philo[i].info.stat_meal.mutex);
	(void)table;
	(void)ptr_null;
}
