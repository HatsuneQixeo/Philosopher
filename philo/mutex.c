/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:28:07 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 02:28:08 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

int	default_mutex_init(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL));
}

void	mutex_report(t_ftmutex ft_mutex, pthread_mutex_t *mutex)
{
	char	*report;
	int		value;

	value = ft_mutex(mutex);
	if (!value)
		return ;
	else if (ft_mutex == default_mutex_init)
		report = "init";
	else if (ft_mutex == pthread_mutex_lock)
		report = "lock";
	else if (ft_mutex == pthread_mutex_unlock)
		report = "unlock";
	else if (ft_mutex == pthread_mutex_destroy)
		report = "destroy";
	else
		report = "undefined function";
	printf("%s returned: %d\n", report, value);
}

int	stat_get(t_stat *stat)
{
	int	status;

	mutex_report(pthread_mutex_lock, &stat->mutex);
	status = stat->status;
	mutex_report(pthread_mutex_unlock, &stat->mutex);
	return (status);
}

void	stat_set(t_stat *stat, int set)
{
	mutex_report(pthread_mutex_lock, &stat->mutex);
	stat->status = set;
	mutex_report(pthread_mutex_unlock, &stat->mutex);
}
