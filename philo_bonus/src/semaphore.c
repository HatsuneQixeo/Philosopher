/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/07 18:59:45 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

int	stat_get(t_stat *stat)
{
	int	status;

	sem_wait(stat->sem);
	status = stat->status;
	sem_post(stat->sem);
	return (status);
}

// Unused currently
void	stat_set(t_stat *stat, int set)
{
	sem_wait(stat->sem);
	stat->status = set;
	sem_post(stat->sem);
}
