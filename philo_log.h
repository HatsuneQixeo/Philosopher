#ifndef PHILO_LOG_H
# define PHILO_LOG_H

# include <pthread.h>

typedef struct s_log
{
	pthread_mutex_t	mutex;
	void			*log;
}				t_log;

void	log_eating(t_log *log);
void	log_sleeping(t_log *log);
void	log_getfork(t_log *log);
void	log_thinking(t_log *log);
void	log_died(t_log *log);

#endif