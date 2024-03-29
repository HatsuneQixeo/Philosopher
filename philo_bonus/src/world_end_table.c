/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_end_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:56:49 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:42 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"
#define PHILO	"philo_"

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

int	philo_evaluate(char **argv)
{
	int	i;
	int	valid;

	i = -1;
	valid = 1;
	while (argv[++i] != NULL && i <= 4)
		valid &= philo_validarg(i, argv[i]);
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
		table.meal_end = 1;
		table.loop_end = 0;
	}
	else
	{
		table.meal_end = ft_atoi(argv[5]);
		table.loop_end = 1;
	}
	gettimeofday(&table.time_start, NULL);
	table.forks = ft_sem_renew(PHILO"forks", 0660, table.member);
	table.sem_log = ft_sem_renew(PHILO"log", 0660, 01);
	table.sem_end = ft_sem_renew(PHILO"end", 0660, 0);
	return (table);
}
