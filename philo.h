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

void	philosopher(char **argv);

//Utils
void	philo_do(t_philo *philo, int time);
void	philo_think(t_philo *philo);
long	philo_time(t_table *table);
void	mutex_do(void *ptr, pthread_mutex_t *mutex, void (*ft_do)());
void	philo_log(t_philo *philo, const char *action);

void	philo_getforks(t_philo *philo);
void	philo_putforks(t_philo *philo);

#endif