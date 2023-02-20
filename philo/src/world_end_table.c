/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_end_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:08:12 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
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

//		valid &= philo_validarg(i, argv[i]);
//	is the same as:
//		if (!philo_validarg(i, argv[i]))
//			valid = 0;
//	under this specific context
//		The purpose of this is to evaluate every arguments
//		and show every error with the given arguments before exitting
//	A more readable approach would be:
//	valid = min(valid, philo_validarg(i, argv[i]))
//	, sucks that c doesn't have it built in
//	, but bitwise is probably the fastest anyway
int	philo_evaluate(char **argv)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	while (argv[++i] != NULL)
		valid &= philo_validarg(i - 1, argv[i]);
	return (valid);
}

t_table	world_end_table(char **argv)
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
		table.loop = loop_postincrement;
	}
	gettimeofday(&table.time_start, NULL);
	mutex_report(default_mutex_init, &table.mutex_log);
	mutex_report(default_mutex_init, &table.stat_end.mutex);
	return (table);
}
