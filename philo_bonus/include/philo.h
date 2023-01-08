/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:17 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/08 18:51:54 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// usleep, write, fork
# include <unistd.h>
// exit, malloc, free
# include <stdlib.h>
// printf
# include <stdio.h>
// create, detach, join
# include <pthread.h>
// gettimeofday
# include <sys/time.h>
// open, close, post, wait, unlink
# include <semaphore.h>

typedef int	(*t_loop)(int *);

typedef struct s_info
{
	int		id;
	int		eaten;
	long	last_meal;
}			t_info;

typedef struct s_table
{
	int				member;
	int				countdown;
	int				meal_duration;
	int				sleep_duration;
	int				meal_end;
	t_loop			loop;
	sem_t			*forks;
	sem_t			*sem_log;
	struct timeval	time_start;
}			t_table;

typedef struct s_philo
{
	t_info	info;
	t_table	table;
}			t_philo;

typedef int (*ft_sem)(sem_t *sem);
void	semaphore_report(ft_sem ft, sem_t *sem);
#endif
