#include "philo.h"

int	philo_time(t_table *table)
{
	t_time	time;

	gettimeofday(&time, 0);
	return (((time.tv_sec - table->start.tv_sec) * MS)
		+ ((time.tv_usec - table->start.tv_usec) / MS));
}

void	philo_do(t_philo *philo, int time)
{
	int	wait;
	int	longing;

	wait = philo_time(philo->table);
	longing = wait;
	while (longing - wait < time)
	{
		// if (longing > philo->info.last_meal + philo->table->countdown)
		// {
		// 	philo_log(philo, DEATH);
		// 	stat_set(&philo->table->end, DIED);
		// 	return ;
		// }
		// else
		// {
			usleep(500);
			longing = philo_time(philo->table);
		// }
	}
}

// void	philo_think(t_philo *philo)
// {
// 	int	longing;

// 	longing = philo_time(philo->table);
// 	while (stat_get(philo->lfork) == TAKEN || stat_get(philo->rfork) == TAKEN)
// 	{
// 		// if (longing - philo->info.last_meal > philo->table->countdown)
// 		// {
// 		// 	philo_log(philo, DEATH);
// 		// 	stat_set(&philo->table->end, DIED);
// 		// 	return ;
// 		// }
// 		// else
// 		// {
// 			usleep(WAIT);
// 			longing = philo_time(philo->table);
// 		// }
// 	}
// }
