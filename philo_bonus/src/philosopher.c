/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:41 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

static void	philo_arrival(t_table *table)
{
	table->str_pid = malloc(sizeof(pid_t) * table->member);
	table->str_philo = malloc(sizeof(t_philo) * table->member);
	philo_iter(piter_init_philo, table);
	philo_iter(piter_init_sim, table);
	philo_sim_status(table);
	philo_iter(piter_clean_philo, table);
	semaphore_report(sem_close, table->forks);
	semaphore_report(sem_close, table->sem_log);
	semaphore_report(sem_close, table->sem_end);
	free(table->str_pid);
	free(table->str_philo);
}

int	philosopher(char **argv)
{
	t_table	table;

	if (!philo_evaluate(argv + 1))
		return (1);
	table = world_end_table(argv);
	if (table.sem_end == SEM_FAILED
		|| table.sem_log == SEM_FAILED
		|| table.forks == SEM_FAILED)
		return (1);
	philo_arrival(&table);
	return (0);
}
