/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:49:00 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 13:58:22 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Unlink the existing semaphore with the same name
//	and return sem_open() with given arguments
sem_t	*ft_sem_renew(const char *name, int permission, int amount)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT, permission, amount));
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
	printf("%s returned: %d\n", ftname, value);
}
