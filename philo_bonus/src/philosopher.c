/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/08 20:57:07 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

static void	philo_cleanup(pid_t *str_pid, t_table *table)
{
	pid_t	*end;

	end = str_pid + table->member;
	while (str_pid != end)
		waitpid(*str_pid++, NULL, 0);
	sem_close(table->sem_log);
	sem_close(table->forks);
}

static void	philo_arrival(t_table table)
{
	t_philo	philo;
	pid_t	*str_pid;
	t_philo	*str_philo;

	philo = (t_philo){(t_info){0, 0, 0}, table};
	str_pid = malloc(sizeof(*str_pid) * table.member);
	str_philo = malloc(sizeof(*str_philo) * table.member);
	while (++philo.info.id <= table.member)
	{
		str_philo[philo.info.id - 1] = philo;
		str_pid[philo.info.id - 1] = fork();
		if (str_pid[philo.info.id - 1] == 0)
			philo_simulation(&str_philo[philo.info.id - 1]);
	}
	philo_cleanup(str_pid, &table);
	free(str_pid);
	free(str_philo);
}

int	philosopher(char **argv)
{
	t_table	table;

	if (!philo_evaluate(argv + 1))
		return (1);
	table = world_end_table(argv);
	if (table.forks == SEM_FAILED || table.sem_log == SEM_FAILED)
		return (!!printf("Semaphore failed\n"));
	philo_arrival(table);
	return (0);
}
