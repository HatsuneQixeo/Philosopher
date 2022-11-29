#include "philo.h"

static void	iteristr_philo_argv(int i, char *str)
{
	const char	*index[5] = {NOPHL, TDIE, TEAT, TSLP, NOFIN};
	int			nbr;

	if (i > 4)
		return ;
	else if (!ft_strisnumeric(str))
		exit(!printf("%s should contain only integer\n", index[i]) + 2);
	nbr = ft_atoi(str);
	if (!nbr)
		printf("%s could not be left blank\n", index[i]);
	else if (nbr < 0)
		printf("%s could not be negative\n", index[i]);
	else
		return ;
	exit(2);
}

static t_table	world_end_table(char **argv)
{
	t_table	table;

	ft_strlistiteri(argv + 1, iteristr_philo_argv);
	table.member = ft_atoi(argv[1]);
	table.countdown = ft_atoi(argv[2]);
	table.meal_duration = ft_atoi(argv[3]);
	table.sleep_duration = ft_atoi(argv[4]);
	if (argv[5])
	{
		table.loop_end = ft_atoi(argv[5]);
		table.loop = loop_increment;
	}
	else
	{
		table.loop_end = 1;
		table.loop = loop_static;
	}
	gettimeofday(&table.start, 0);
	mutex_report(default_mutex_init, &table.log.mutex);
	mutex_report(default_mutex_init, &table.end.mutex);
	return (table);
}

static void	philo_for(t_table *table, void *ptr_main, void *ptr_2nd, void (*ft)())
{
	int	i;

	i = -1;
	while (++i < table->member)
		ft(table, ptr_main, i, ptr_2nd);
}

void	philosopher(char **argv)
{
	t_table		table;
	pthread_t	*str_thread;
	t_mutex		*str_fork;
	t_philo		*str_philo;

	table = world_end_table(argv);
	if (!table.member)
		return ;
	str_fork = malloc(table.member * sizeof(t_mutex));
	str_philo = malloc(table.member * sizeof(t_philo));
	str_thread = malloc(table.member * sizeof(pthread_t));
	philo_for(&table, str_fork, 0, init_fork);
	philo_for(&table, str_philo, str_fork, init_philo);
	philo_for(&table, str_thread, str_philo, start_simulation);
	philo_for(&table, str_thread, 0, end_simulation);
	free(str_thread);
	free(str_fork);
	free(str_philo);
}
