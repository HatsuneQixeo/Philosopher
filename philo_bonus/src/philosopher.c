/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/07 18:59:45 by hqixeo           ###   ########.fr       */
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

//	Unlink the existing semaphore with the same name
//	and return sem_open() with given arguments
sem_t	*ft_sem_renew(const char *name, int permission, int amount)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT, permission, amount));
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
	table.forks = ft_sem_renew(PHILO"forks", 0660, table.member);
	table.sem_log = ft_sem_renew(PHILO"log", 0660, 1);
	table.stat_end.sem = ft_sem_renew(PHILO"end", 0660, 1);
	return (table);
}

static void	philo_end(pid_t *str_pid, t_table *table)
{
	pid_t	*end;

	end = str_pid + table->member;
	while (str_pid != end)
		waitpid(*str_pid++, NULL, 0);
	sem_close(table->stat_end.sem);
	sem_close(table->sem_log);
	sem_close(table->forks);
}

static void	philo_begin(t_table *table)
{
	t_philo	philo;
	pid_t	str_pid[table->member];
	t_philo	str_philo[table->member];

	philo = (t_philo){(t_info){0, 0, 0}, table};
	while (++philo.info.id <= table->member)
	{
		str_philo[philo.info.id - 1] = philo;
		str_pid[philo.info.id - 1] = fork();
		if (str_pid[philo.info.id - 1] == 0)
			ft_simulation(&str_philo[philo.info.id - 1]);
	}
	philo_end(str_pid, table);
}

int	philosopher(char **argv)
{
	t_table	table;

	if (!philo_evaluate(argv + 1))
		return (1);
	table = world_end_table(argv);
	if (table.forks == SEM_FAILED
		|| table.sem_log == SEM_FAILED
		|| table.stat_end.sem == SEM_FAILED)
		return (!!printf("Semaphore failed\n"));
	philo_begin(&table);
	return (0);
}
