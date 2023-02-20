/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrival.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:08:12 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

static void	philo_arrival(int i, t_table *table,
			void *ptr_thread, void *ptr_philo)
{
	pthread_t	*thread;
	t_philo		*philo;

	thread = ptr_thread;
	philo = ptr_philo;
	pthread_create(&thread[i], NULL, philo_simulation, &philo[i]);
	(void)table;
}

void	iter_batch_odd(int i, t_table *table,
			void *ptr_thread, void *ptr_philo)
{
	if ((i + 1) % 2 == 1)
		philo_arrival(i, table, ptr_thread, ptr_philo);
}

void	iter_batch_even(int i, t_table *table,
			void *ptr_thread, void *ptr_philo)
{
	if ((i + 1) % 2 == 0)
		philo_arrival(i, table, ptr_thread, ptr_philo);
}
