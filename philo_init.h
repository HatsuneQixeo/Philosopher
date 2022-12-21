#ifndef PHILO_INIT_H
# define PHILO_INIT_H

//libft
#define NOPHL	"number_of_philosophers"
#define TDIE	"time_to_die"
#define TEAT	"time_to_eat"
#define TSLP	"time_to_sleep"
#define NOFIN	"number_of_times_each_philosopher_must_eat"

//printf
#include <stdio.h>
//malloc, free
#include <stdlib.h>
//create, detach, join
//mutex: init, destroy, lock, unlock
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include "libft/include/libft.h"

typedef int (*t_loop)(int *);
typedef int (*t_ftmutex)(pthread_mutex_t *);
typedef struct timeval t_time;

typedef struct s_stat
{
	pthread_mutex_t	mutex;
	int				status;
}			t_stat;

typedef struct s_info
{
	int		id;
	int		eaten;
	t_stat	last_meal;
}			t_info;

typedef struct s_table
{
	int		member;
	int		countdown;
	int		meal_duration;
	int		sleep_duration;
	t_loop	loop;
	t_time	start;
	t_stat	end;
}			t_table;

typedef struct s_philo
{
	t_info	info;
	t_table	*table;
	t_stat	*lfork;
	t_stat	*rfork;
}			t_philo;

//Loop type
int		loop_static(int *nbr);
int		loop_increment(int *nbr);

//libft
int		ft_strisnumeric(const char *str);
int		ft_atoi(const char *str);

//Mutex
int		default_mutex_init(pthread_mutex_t *mutex);
void	mutex_report(t_ftmutex ft_stat, pthread_mutex_t *mutex);

void	init_fork(t_table *table, int i, void *ptr_forks, void *ptr_null);
void	init_philo(t_table *table, int i, void *ptr_philo, void *ptr_forks);
void	sim_start(t_table *table, int i, void *ptr_thread, void *ptr_philo);
void	sim_end(t_table *table, int i, void *ptr_thread, void *ptr_null);

typedef void (*t_iter)(t_table *, int, void *, void *);

void	*ft_simulation(void *ptr);

#endif
