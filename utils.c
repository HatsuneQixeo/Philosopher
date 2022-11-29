#include "philo.h"

long	philo_time(t_table *table)
{
	t_time	time;

	gettimeofday(&time, 0);
	return (((time.tv_sec - table->start.tv_sec) * MS)
		+ ((time.tv_usec - table->start.tv_usec) / MS));
}

void	philo_died(t_mutex *end)
{
	end->status = -1;
}

int	mutex_get(t_mutex *fork)
{
	int	status;

	mutex_report(pthread_mutex_lock, &fork->mutex);
	status = (int)fork->ptr;
	mutex_report(pthread_mutex_unlock, &fork->mutex);
	return (status);
}

void	philo_do(t_philo *philo, int time)
{
	long	wait;
	long	longing;

	wait = philo_time(philo->table);
	longing = wait;
	while (longing - wait < time)
	{
		if (longing > philo->info.last_meal + philo->table->countdown)
		{
			philo_log(philo, DEATH);
			mutex_do(philo->table->end, &philo->table->end.mutex, philo_died);
			return ;
		}
		else
		{
			usleep(WAIT);
			longing = philo_time(philo->table);
		}
	}
}

void	philo_think(t_philo *philo)
{
	long	longing;

	longing = philo_time(philo->table);
	while (!mutex_get(philo->lfork) || !mutex_get(philo->rfork))
	{
		if (longing - philo->info.last_meal > philo->table->countdown)
		{
			philo_log(philo, DEATH);
			mutex_do(philo->table, &philo->table->end, philo_died);
			return ;
		}
		else
		{
			usleep(WAIT);
			longing = philo_time(philo->table);
		}
	}
}

void	mutex_do(void *ptr, pthread_mutex_t *mutex, void (*ft_do)())
{
	mutex_report(pthread_mutex_lock, mutex);
	ft_do(ptr);
	mutex_report(pthread_mutex_unlock, mutex);
}
