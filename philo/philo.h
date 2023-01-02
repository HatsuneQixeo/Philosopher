/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:29:46 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 02:29:48 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//printf
# include <stdio.h>
//create, detach, join
//mutex: init, destroy, lock, unlock
# include <pthread.h>
# include <sys/time.h>

# define TAKEN		0
# define AVAILABLE	1
# define DIED		-1

typedef int	(*t_loop)(int *);
typedef int	(*t_ftmutex)(pthread_mutex_t *);

typedef struct s_info
{
	int		id;
	int		eaten;
	long	last_meal;
}			t_info;

typedef struct s_stat
{
	pthread_mutex_t	mutex;
	int				status;
}			t_stat;

typedef struct s_table
{
	int				member;
	int				countdown;
	int				meal_duration;
	int				sleep_duration;
	t_loop			loop;
	t_stat			end;
	struct timeval	start;
}			t_table;

typedef struct s_philo
{
	t_info	info;
	t_table	*table;
	t_stat	*lfork;
	t_stat	*rfork;
}			t_philo;

void	mutex_report(t_ftmutex ft_mutex, pthread_mutex_t *mutex);

#endif
