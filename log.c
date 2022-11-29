#include "philo.h"
#include "philo_log.h"

int	mutex_get(t_mutex *fork);

static void	log(t_philo *philo)
{
	printf("%ld %d %s\n", philo_time(philo->table),
		philo->info.id, philo->table->log.ptr);
}

void	philo_log(t_philo *philo, const char *action)
{
	if (mutex_get(&philo->table->end) == -1)
		return ;
		(void)action;
	// philo->info.status = action;
	// mutex_do(philo->table.)
	mutex_do(philo, &philo->table->log.mutex, log);
}
