#include "philo.h"

static bool	philo_validarg(int i, const char *arg)
{
	static const char	*type[5] = {NOPHL, TDIE, TEAT, TSLP, NOFIN};
	int					nbr;

	nbr = ft_atoi(arg);
	if (arg[0] == '\0')
		printf("%s:(%s) could not be left blank\n", type[i], arg);
	else if (ft_strisnumeric(arg) == false)
		printf("%s:(%s) should contain only integer\n", type[i], arg) ;
	else if (nbr == 0)
		printf("%s:(%s) could not be left blank\n", type[i], arg);
	else if (nbr < 0)
		printf("%s:(%s) could not be negative\n", type[i], arg);
	else
		return (true);
	return (false);
}

static bool	philo_evaluate(char **argv)
{
	int			i;
	bool		valid;

	i = -1;
	valid = true;
	while (argv[++i] && i <= 4)
		if (philo_validarg(i, argv[i]) == false)
			valid = false;
	return (valid);
}

static t_table	world_end_table(char **argv)
{
	t_table	table;

	table.member = ft_atoi(argv[1]);
	table.countdown = ft_atoi(argv[2]);
	table.meal_duration = ft_atoi(argv[3]);
	table.sleep_duration = ft_atoi(argv[4]);
	if (argv[5])
	{
		table.end.status = ft_atoi(argv[5]);
		table.loop = loop_increment;
	}
	else
	{
		table.end.status = 1;
		table.loop = loop_static;
	}
	gettimeofday(&table.start, NULL);
	mutex_report(default_mutex_init, &table.end.mutex);
	return (table);
}



static void	philo_for(t_table *table, t_iter ft_iter, void *arg1, void *arg2)
{
	int	i;

	i = -1;
	while (++i < table->member)
		ft_iter(table, i, arg1, arg2);
}

void	philo_monitor(t_philo *const str_philo)
{
	t_philo	*it;
	const t_philo	*end = str_philo + str_philo->table->member;

	while (1)
	{
		it = str_philo - 1;
		// printf("re\n");
		while (++it < end)
		{
			// printf("it\n");
			if (philo_time(it->table) - stat_get(&it->info.last_meal) <= it->table->countdown)
				continue ;
			philo_log(it, DEATH);
			stat_set(&it->table->end, DIED);
			return ;
		}
	}
}


int	philosopher(char **argv)
{
	t_table		table;
	pthread_t	*str_thread;
	t_stat		*str_fork;
	t_philo		*str_philo;

	if (philo_evaluate(argv + 1) == false)
		return (1);
	table = world_end_table(argv);
	str_fork = malloc(table.member * sizeof(t_stat));
	str_philo = malloc(table.member * sizeof(t_philo));
	str_thread = malloc(table.member * sizeof(pthread_t));
	philo_for(&table, init_fork, str_fork, NULL);
	philo_for(&table, init_philo, str_philo, str_fork);
	philo_for(&table, sim_start, str_thread, str_philo);
	philo_monitor(str_philo);
	philo_for(&table, sim_end, str_thread, NULL);
	free(str_thread);
	free(str_fork);
	free(str_philo);
	return (0);
}
