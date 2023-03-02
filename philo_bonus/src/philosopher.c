/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:43 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

void	piter_happyend(int i, t_table *table)
{
	semaphore_report(sem_wait, table->sem_end);
	(void)i;
}

void	philo_iter(t_piter ft_iter, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->member)
		ft_iter(i, table);
}

void	philo_sim_status(t_table *table)
{
	pid_t	happyend;
	pid_t	first_exit;

	happyend = fork();
	if (happyend == -1)
		return ((void)printf("Fork error\n"));
	else if (happyend == CHILD)
	{
		philo_iter(piter_happyend, table);
		exit(0);
	}
	else
		first_exit = waitpid(-1, NULL, 0);
	if (first_exit != happyend)
	{
		printf("Someone died\n");
		kill(happyend, SIGINT);
	}
	else
		printf("Happy End\n");
}

static void	philo_arrival(t_table *table)
{
	table->str_pid = malloc(sizeof(pid_t) * table->member);
	table->str_philo = malloc(sizeof(t_philo) * table->member);
	philo_iter(piter_init_philo, table);
	philo_iter(piter_init_sim, table);
	philo_sim_status(table);
	philo_iter(piter_clean_process, table);
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
	philo_arrival(&table);
	// Forbidden
	system("leaks -q philo_bonus");
	return (0);
}
