#include "philo_log.h"

void	log_eating(t_log *log)
{
	log->log = "is eating";
}

void	log_sleeping(t_log *log)
{
	log->log = "is sleeping";
}

void	log_getfork(t_log *log)
{
	log->log = "has taken a fork";
}

void	log_thinking(t_log *log)
{
	log->log = "is thinking";
}

void	log_died(t_log *log)
{
	log->log = "died";
}
