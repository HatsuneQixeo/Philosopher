#include "philo.h"

void	philo_log(t_philo *philo, const char *action)
{
	static pthread_mutex_t	mutex_log = PTHREAD_MUTEX_INITIALIZER;

	if (stat_get(&philo->table->end) == DIED)
		return ;
	mutex_report(pthread_mutex_lock, &mutex_log);
	printf("%d %d %s\n", philo_time(philo->table), philo->info.id, action);
	mutex_report(pthread_mutex_unlock, &mutex_log);
}

void	philo_getforks(t_philo *philo)
{
	mutex_report(pthread_mutex_lock, &philo->lfork->mutex);
	philo_log(philo, GETFORK);
	mutex_report(pthread_mutex_lock, &philo->rfork->mutex);
	philo_log(philo, GETFORK);
}

void	philo_putforks(t_philo *philo)
{
	mutex_report(pthread_mutex_unlock, &philo->lfork->mutex);
	mutex_report(pthread_mutex_unlock, &philo->rfork->mutex);
}
