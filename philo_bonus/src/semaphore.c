/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:49:00 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:43 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Unlink the existing semaphore with the same name
//	and return sem_open() with given arguments
sem_t	*ft_sem_renew(const char *name, int permission, int amount)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, permission, amount);
	if (sem == SEM_FAILED)
		printf("Failed to open: %s\n", name);
	else
		printf("Newsem(%s): %p\n", name, sem);
	//Forbidden
	if (sem_unlink(name) == -1)
		perror(name);
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

void	stat_set(t_stat *stat, long set)
{
	semaphore_report(sem_wait, stat->sem);
	stat->status = set;
	semaphore_report(sem_post, stat->sem);
}

long	stat_get(t_stat *stat)
{
	long	status;

	semaphore_report(sem_wait, stat->sem);
	status = stat->status;
	semaphore_report(sem_post, stat->sem);
	return (status);
}
