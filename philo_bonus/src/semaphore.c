/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:49:00 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:42 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Unlink the existing semaphore with the same name
//	and return sem_open() with given arguments
sem_t	*ft_sem_renew(const char *name, int permission, int amount)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, permission, amount);
	if (sem == SEM_FAILED)
		printf("Failed to open: %s\n", name);
	else
		sem_unlink(name);
	return (sem);
}

void	semaphore_report(t_ftsem ft, sem_t *sem)
{
	const char	*ftname;
	int			value;

	value = ft(sem);
	if (value == 0)
		return ;
	else if (ft == sem_wait)
		ftname = "sem_wait";
	else if (ft == sem_post)
		ftname = "sem_post";
	else if (ft == sem_close)
		ftname = "sem_close";
	else
		ftname = "undefined_function";
	printf("semaphore_report: %s(%p) returned: %d\n", ftname, sem, value);
}

void	time_set(t_time *time)
{
	semaphore_report(sem_wait, time->sem);
	gettimeofday(&time->s_time, NULL);
	semaphore_report(sem_post, time->sem);
}

time_t	time_get(t_time *time, struct timeval start)
{
	time_t	status;

	semaphore_report(sem_wait, time->sem);
	status = (time->s_time.tv_sec - start.tv_sec) * 1000
		+ (time->s_time.tv_usec - start.tv_usec) / 1000;
	semaphore_report(sem_post, time->sem);
	return (status);
}
