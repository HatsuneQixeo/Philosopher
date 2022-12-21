#include "philo.h"

void	philo_eat(t_philo *philo)
{
	philo_getforks(philo);
	stat_set(&philo->info.last_meal, philo_time(philo->table));
	philo_log(philo, EAT);
	philo_do(philo, philo->table->meal_duration);
	philo->table->loop(&philo->info.eaten);
	philo_putforks(philo);
}

void	*ft_simulation(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	stat_set(&philo->info.last_meal, philo_time(philo->table));
	if (philo->info.id % 2)
		philo_do(philo, 5);
	while (philo->info.eaten < stat_get(&philo->table->end))
	{
		// philo_think(philo);
		philo_eat(philo);
		philo_log(philo, SLEEP);
		if (philo->info.eaten >= stat_get(&philo->table->end))
			break ;
		philo_do(philo, philo->table->sleep_duration);
		philo_log(philo, THINK);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc < 5)
		printf("Field: [required] {optional}\n"
			"Note: time is calculated in miliseconds\n"
			"./philo [%s] [%s] [%s] [%s] {%s}\n",
			NOPHL, TDIE, TEAT, TSLP, NOFIN);
	else if (argc > 6)
		printf("Excessive arguments!\n");
	else
		return (philosopher(argv));
	return (1);
}
