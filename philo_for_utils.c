#include "philo.h"

void	init_fork(t_table *table, int i, void *ptr_forks, void *ptr_null)
{
	t_stat	*fork;

	fork = ptr_forks;
	fork[i].status = AVAILABLE;
	mutex_report(default_mutex_init, &fork[i].mutex);
	(void)table;
	(void)ptr_null;
}

void	init_philo(t_table *table, int i, void *ptr_philo, void *ptr_forks)
{
	t_philo	*philo;
	t_stat	*forks;

	philo = ptr_philo;
	forks = ptr_forks;
	philo[i].info.id = i + 1;
	philo[i].info.eaten = 0;
	mutex_report(default_mutex_init, &philo[i].info.last_meal.mutex);
	philo[i].info.last_meal.status = philo_time(table);
	philo[i].table = table;
	philo[i].lfork = &forks[i];
	philo[i].rfork = &forks[(i + 1) % table->member];
}

void	sim_start(t_table *table, int i, void *ptr_thread, void *ptr_philo)
{
	pthread_t	*thread;
	t_philo		*philo;

	thread = ptr_thread;
	philo = ptr_philo;
	pthread_create(&thread[i], NULL, ft_simulation, &philo[i]);
	(void)table;
}

void	sim_end(t_table *table, int i, void *ptr_thread, void *ptr_null)
{
	pthread_t	*thread;

	thread = ptr_thread;
	pthread_join(thread[i], NULL);
	(void)table;
	(void)ptr_null;
}
