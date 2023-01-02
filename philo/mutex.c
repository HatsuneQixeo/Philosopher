/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:19:18 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 05:16:47 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

int	default_mutex_init(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL));
}

void	mutex_report(t_ftmutex ft_mutex, pthread_mutex_t *mutex)
{
	char	*ftname;
	int		value;

	value = ft_mutex(mutex);
	if (!value)
		return ;
	else if (ft_mutex == default_mutex_init)
		ftname = "default_mutex_init";
	else if (ft_mutex == pthread_mutex_lock)
		ftname = "pthread_mutex_lock";
	else if (ft_mutex == pthread_mutex_unlock)
		ftname = "pthread_mutex_unlock";
	else if (ft_mutex == pthread_mutex_destroy)
		ftname = "pthread_mutex_destroy";
	else
		ftname = "undefined function";
	printf("%s returned: %d\n", ftname, value);
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
