/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// printf
# include <stdio.h>
// create, detach, join
// mutex: init, destroy, lock, unlock
# include <pthread.h>
// usleep
# include <unistd.h>
# include <sys/time.h>

# define TAKEN		0
# define AVAILABLE	1

# define DEFAULT	"\033[0m"
# define CYAN		"\033[0;36m"
# define RED		"\033[0;31m"

typedef int		(*t_loop)(int *);
typedef int		(*t_ftmutex)(pthread_mutex_t *);

typedef struct s_stat
{
	pthread_mutex_t	mutex;
	long			status;
}			t_stat;

typedef struct s_info
{
	int		id;
	int		eaten;
	t_stat	stat_meal;
}			t_info;

typedef struct s_table
{
	int				member;
	int				countdown;
	int				meal_duration;
	int				sleep_duration;
	int				loop_end;
	t_stat			stat_end;
	pthread_mutex_t	mutex_log;
	struct timeval	time_start;
}			t_table;

typedef struct s_philo
{
	t_info			info;
	t_table			*table;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
}			t_philo;

void	mutex_report(t_ftmutex ft_mutex, pthread_mutex_t *mutex);

typedef void	(*t_iter)(unsigned int i, t_table *table,
			void *arg1, void *arg2);
void	philo_for(t_iter ft_iter, t_table *table, void *arg1, void *arg2);

t_info	default_info_init(int id);
#endif
