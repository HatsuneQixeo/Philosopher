#include "philo.h"

void	init_fork(t_table *table, void *ptr_forks, int i)
{
	t_mutex	*fork;

	fork = ptr_forks;
	fork[i].nbr = 1;
	mutex_report(default_mutex_init, &fork[i].mutex);
	(void)table;
}

void	init_philo(t_table *table, void *ptr_philo, int i, void *ptr_forks)
{
	t_philo	*philo;
	t_mutex	*forks;

	philo = ptr_philo;
	forks = ptr_forks;
	philo[i] = (t_philo){(t_info){i + 1, 0, philo_time(table), 0}, table,
		&forks[i], &forks[(i + 1) % table->member]};
}

void	start_simulation(t_table *table, void *ptr_thread, int i, void *ptr_philo)
{
	pthread_t	*thread;
	t_philo		*philo;

	thread = ptr_thread;
	philo = ptr_philo;
	pthread_create(&thread[i], 0, ft_simulation, &philo[i]);
	(void)table;
}

void	end_simulation(t_table *table, void *ptr_thread, int i)
{
	pthread_t	*thread;

	thread = ptr_thread;
	pthread_join(thread[i], 0);
	(void)table;
}
