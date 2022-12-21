#include "philo.h"

int	default_mutex_init(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL));
}

void	mutex_report(t_ftmutex ft_mutex, pthread_mutex_t *mutex)
{
	char	*report;
	int		value;

	value = ft_mutex(mutex);
	if (!value)
		return ;
	else if (ft_mutex == default_mutex_init)
		report = "init";
	else if (ft_mutex == pthread_mutex_lock)
		report = "lock";
	else if (ft_mutex == pthread_mutex_unlock)
		report = "unlock";
	else if (ft_mutex == pthread_mutex_destroy)
		report = "destroy";
	else
		report = "undefined function";
	printf("%s returned: %d\n", report, value);
}
