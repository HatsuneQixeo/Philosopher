/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:17 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:42 by hqixeo           ###   ########.fr       */
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

typedef struct s_time
{
	sem_t			*sem;
	struct timeval	s_time;
}			t_time;

typedef struct s_info
{
	int		id;
	int		eaten;
	t_time	time_lastmeal;
}			t_info;

typedef struct s_table
{
	int				member;
	int				countdown;
	int				meal_duration;
	int				sleep_duration;
	int				meal_end;
	int				loop_end;
	sem_t			*forks;
	sem_t			*sem_log;
	sem_t			*sem_end;
	struct timeval	time_start;
	pid_t			*str_pid;
	struct s_philo	*str_philo;
}			t_table;

typedef struct s_philo
{
	t_info	info;
	t_table	*table;
}			t_philo;

typedef int		(*t_ftsem)(sem_t *sem);
typedef void	(*t_piter)(unsigned int i, t_table *table);
void	semaphore_report(t_ftsem ft, sem_t *sem);
#endif
