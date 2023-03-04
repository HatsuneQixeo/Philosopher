/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:52:41 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:41 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

static void	piter_happyend(unsigned int i, t_table *table)
{
	semaphore_report(sem_wait, table->sem_end);
	(void)i;
}

static void	piter_badend(unsigned int i, t_table *table)
{
	if (kill(table->str_pid[i], SIGINT) != -1)
		waitpid(table->str_pid[i], NULL, 0);
}

static int	philo_simend(pid_t happyend)
{
	pid_t	first_exit;
	int		status;

	while (1)
	{
		first_exit = waitpid(-1, &status, 0);
		if (first_exit == happyend)
			return (0);
		else if (first_exit == -1)
			break ;
		else if (status == 0)
			continue ;
		else if (first_exit != happyend)
			return (1);
	}
	return (-1);
}

void	philo_sim_status(t_table *table)
{
	pid_t	happyend;

	happyend = fork();
	if (happyend == -1)
		printf("Fork error\n");
	else if (happyend == 0)
	{
		philo_iter(piter_happyend, table);
		exit(0);
	}
	else if (philo_simend(happyend) == 1)
	{
		kill(happyend, SIGINT);
		philo_iter(piter_badend, table);
	}
}
