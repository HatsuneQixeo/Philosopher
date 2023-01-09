/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_for_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 13:58:22 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

void	init_fork(int i, t_table *table, void *ptr_forks, void *ptr_null)
{
	t_stat	*fork;

	fork = ptr_forks;
	fork[i].status = AVAILABLE;
	mutex_report(default_mutex_init, &fork[i].mutex);
	(void)table;
	(void)ptr_null;
}

void	init_philo(int i, t_table *table, void *ptr_philo, void *ptr_forks)
{
	t_philo	*philo;
	t_stat	*forks;

	philo = ptr_philo;
	forks = ptr_forks;
	philo[i] = (t_philo){(t_info){i + 1, 0, 0}, table,
		&forks[i], &forks[(i + 1) % table->member]};
}

void	sim_begin(int i, t_table *table, void *ptr_thread, void *ptr_philo)
{
	pthread_t	*thread;
	t_philo		*philo;

	thread = ptr_thread;
	philo = ptr_philo;
	pthread_create(&thread[i], NULL, ft_simulation, &philo[i]);
	(void)table;
}

void	sim_end(int i, t_table *table, void *ptr_thread, void *ptr_null)
{
	pthread_t	*thread;

	thread = ptr_thread;
	pthread_join(thread[i], NULL);
	(void)table;
	(void)ptr_null;
}

void	destroy_forks(int i, t_table *table, void *ptr_forks, void *ptr_null)
{
	t_stat	*fork;

	fork = ptr_forks;
	mutex_report(pthread_mutex_destroy, &fork[i].mutex);
	(void)table;
	(void)ptr_null;
}
