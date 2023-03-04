/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:43 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:42 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

void	piter_init_philo(unsigned int i, t_table *table)
{
	table->str_philo[i] = (t_philo){default_info_init(i + 1), table};
}

void	piter_init_sim(unsigned int i, t_table *table)
{
	table->str_pid[i] = fork();
	if (table->str_pid[i] == -1)
		printf("Fork error at index: %d\n", i);
	else if (table->str_pid[i] == 0)
		philo_simulation(&table->str_philo[i]);
}

void	piter_clean_philo(unsigned int i, t_table *table)
{
	semaphore_report(sem_close, table->str_philo[i].info.time_lastmeal.sem);
}

void	philo_iter(t_piter ft_iter, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->member)
		ft_iter(i, table);
}
