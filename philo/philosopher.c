/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:19:18 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 05:16:48 by hqixeo           ###   ########.fr       */
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

//	valid &= philo_validarg(i, argv[i]);
// is the same as:
//	if (!philo_validarg(i, argv[i]))
//	valid = 0;
// under this specific context
//		The purpose of this is to evaluate every arguments
// 		and show every error with the given arguments before exitting
//	A more readable approach would be:
//	valid = min(valid, philo_validarg(i, argv[i]))
//	, sucks that c doesn't have it built in
//	, but bitwise is probably the fastest anyway
static int	philo_evaluate(char **argv)
{
	int	i;
	int	valid;

	i = -1;
	valid = 1;
	while (argv[++i] != NULL && i <= 4)
		valid &= philo_validarg(i, argv[i]);
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
		table.stat_end.status = 1;
		table.loop = loop_static;
	}
	else
	{
		table.stat_end.status = ft_atoi(argv[5]);
		table.loop = loop_increment;
	}
	gettimeofday(&table.time_start, NULL);
	mutex_report(default_mutex_init, &table.mutex_log);
	mutex_report(default_mutex_init, &table.stat_end.mutex);
	return (table);
}

static void	philo_for(t_iter ft_iter, t_table *table, void *arg1, void *arg2)
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
	philo_for(init_fork, &table, str_fork, NULL);
	philo_for(init_philo, &table, str_philo, str_fork);
	philo_for(sim_begin, &table, str_thread, str_philo);
	philo_for(sim_end, &table, str_thread, NULL);
	philo_for(destroy_forks, &table, str_fork, NULL);
	mutex_report(pthread_mutex_destroy, &table.mutex_log);
	mutex_report(pthread_mutex_destroy, &table.stat_end.mutex);
	free(str_thread);
	free(str_fork);
	free(str_philo);
	system("leaks -q philo");
	return (0);
}
