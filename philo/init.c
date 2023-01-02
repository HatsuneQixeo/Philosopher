/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 02:28:00 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

static int	philo_validarg(int i, const char *arg)
{
	const char	*type[5] = {NOPHL, TDIE, TEAT, TSLP, NOFIN};
	int			nbr;

	nbr = ft_atoi(arg);
	if (arg[0] == '\0')
		printf("%s:(%s) could not be left blank\n", type[i], arg);
	else if (!ft_strisnumeric(arg))
		printf("%s:(%s) should contain only integer\n", type[i], arg);
	else if (nbr == 0)
		printf("%s:(%s) could not be left blank\n", type[i], arg);
	else if (nbr < 0)
		printf("%s:(%s) could not be negative\n", type[i], arg);
	else
		return (1);
	return (0);
}

static int	philo_evaluate(char **argv)
{
	int	i;
	int	valid;

	i = -1;
	valid = 1;
	while (argv[++i] != NULL && i <= 4)
		if (!philo_validarg(i, argv[i]))
			valid = 0;
	return (valid);
}

static t_table	world_end_table(char **argv)
{
	t_table	table;

	table.member = ft_atoi(argv[1]);
	table.countdown = ft_atoi(argv[2]);
	table.meal_duration = ft_atoi(argv[3]);
	table.sleep_duration = ft_atoi(argv[4]);
	if (argv[5] == NULL)
	{
		table.end.status = 1;
		table.loop = loop_static;
	}
	else
	{
		table.end.status = ft_atoi(argv[5]);
		table.loop = loop_increment;
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
		ft_iter(i, table, arg1, arg2);
}

int	philosopher(char **argv)
{
	t_table		table;
	pthread_t	*str_thread;
	t_stat		*str_fork;
	t_philo		*str_philo;

	if (!philo_evaluate(argv + 1))
		return (1);
	table = world_end_table(argv);
	str_fork = malloc(table.member * sizeof(t_stat));
	str_philo = malloc(table.member * sizeof(t_philo));
	str_thread = malloc(table.member * sizeof(pthread_t));
	philo_for(&table, init_fork, str_fork, NULL);
	philo_for(&table, init_philo, str_philo, str_fork);
	philo_for(&table, sim_begin, str_thread, str_philo);
	philo_for(&table, sim_end, str_thread, NULL);
	free(str_thread);
	free(str_fork);
	free(str_philo);
	return (0);
}
