#include "philo.h"

int	stat_get(t_stat *stat)
{
	int	ret;
	
	mutex_report(pthread_mutex_lock, &stat->mutex);
	ret = stat->status;
	mutex_report(pthread_mutex_unlock, &stat->mutex);
	return (ret);
}

void	stat_set(t_stat *stat, int to)
{
	mutex_report(pthread_mutex_lock, &stat->mutex);
	stat->status = to;
	mutex_report(pthread_mutex_unlock, &stat->mutex);
}
