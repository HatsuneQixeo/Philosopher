#include "philo.h"

void	*ft_simulation(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	philo->info.last_meal = philo_time(philo->table);
	if (philo->info.id % 2)
		philo_do(philo, 1);
	while (philo->info.eaten < philo->table->loop_end)
	{
		philo_think(philo);
		philo_getforks(philo);

		philo->info.last_meal = philo_time(philo->table);
		philo_log(philo, EAT);
		philo_do(philo, philo->table->meal_duration);
		philo->table->loop(&philo->info.eaten);
		philo_putforks(philo);
		if (philo->info.eaten >= philo->table->loop_end)
			break ;

		philo_log(philo, SLEEP);
		philo_do(philo, philo->table->sleep_duration);
		philo_log(philo, THINK);
	}
	if (!ft_strcmp(philo->info.status, DEATH))
		philo_log(philo, DEATH);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Field: [required] {optional}\n");
		printf("Note: time is calculated in miliseconds\n");
		printf("./philo [%s] [%s] [%s] [%s] {%s}\n",
			NOPHL, TDIE, TEAT, TSLP, NOFIN);
		return (1);
	}
	else if (argc > 6)
		printf("Extra arguments will be ignored!\n");
	philosopher(argv);
	// system("leaks -q philo");
}
