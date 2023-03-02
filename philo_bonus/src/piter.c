/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:43 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:43 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

void	piter_init_philo(int i, t_table *table)
{
	table->str_philo[i] = (t_philo){default_info_init(i + 1), table};
}

void	piter_init_sim(int i, t_table *table)
{
	table->str_pid[i] = fork();
	if (table->str_pid[i] == -1)
		printf("Fork error at index: %d\n", i);
	else if (table->str_pid[i] == CHILD)
		philo_simulation(&table->str_philo[i]);
}

void	piter_clean_process(int i, t_table *table)
{
	if (kill(table->str_pid[i], SIGINT) == -1)
		printf("philo_%d is already dead\n", table->str_philo[i].info.id);
	else if (waitpid(table->str_pid[i], NULL, 0) == -1)
		printf("philo_%d is already quitted\n", table->str_philo[i].info.id);
	// else
	// 	printf("joined philo_%d\n", table->str_philo[i].info.id);
}

void	piter_clean_philo(int i, t_table *table)
{
	semaphore_report(sem_close, table->str_philo[i].info.time_lastmeal.sem);
}
