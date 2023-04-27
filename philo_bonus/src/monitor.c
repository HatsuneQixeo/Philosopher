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

static void	piter_badend(unsigned int i, t_table *table)
{
	if (kill(table->str_pid[i], SIGINT) != -1)
		waitpid(table->str_pid[i], NULL, 0);
}

void	philo_sim_status(t_table *table)
{
	int	status;

	status = 0;
	while (status != -1)
	{
		if (waitpid(-1, &status, 0) == -1)
			return ;
	}
	philo_iter(piter_badend, table);
}
