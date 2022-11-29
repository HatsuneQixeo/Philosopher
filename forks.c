#include "philo.h"

static void	fork_take(t_mutex *fork)
{
	fork->ptr = 0;
}

static void	fork_put(t_mutex *fork)
{
	fork->ptr = (void *)1;
}

void	philo_getforks(t_philo *philo)
{
	mutex_do(philo->lfork, &philo->lfork->mutex, fork_take);
	mutex_do(philo->rfork, &philo->rfork->mutex, fork_take);
	philo_log(philo, GETFORK);
	philo_log(philo, GETFORK);
}

void	philo_putforks(t_philo *philo)
{
	mutex_do(philo->lfork, &philo->lfork->mutex, fork_put);
	mutex_do(philo->rfork, &philo->rfork->mutex, fork_put);
}
