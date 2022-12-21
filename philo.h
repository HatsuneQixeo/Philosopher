#ifndef PHILO_H
# define PHILO_H

//memset?
# include <string.h>
//write, usleep
# include <unistd.h>
# include "philo_init.h"
# define MS			1000
# define WAIT		250
# define GETFORK	"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DEATH		"died"
# define TAKEN		0
# define AVAILABLE	1
# define DIED		-1

int		philosopher(char **argv);

//Utils
void	philo_do(t_philo *philo, int time);
void	philo_think(t_philo *philo);

int		stat_get(t_stat *stat);
void	stat_set(t_stat *stat, int to);

void	philo_getforks(t_philo *philo);
void	philo_putforks(t_philo *philo);

int		philo_time(t_table *table);
void	philo_log(t_philo *philo, const char *action);

#endif