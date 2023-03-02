/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:43 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:43 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_simulation.h"

int		g_increment;

time_t	ft_timetoms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec/ 1000);
}

void	*testthread(void *arg)
{
	t_stat	*stat;

	stat = arg;
	for (int i = 0; i < g_increment; i++)
	{
		semaphore_report(sem_post, stat->sem);
		gettimeofday(&stat->s_time, NULL);
		time_t	start = ft_timetoms(stat->s_time);
		printf("time: %ld\n", start);
		semaphore_report(sem_wait, stat->sem);
	}
	return (NULL);
}

void	sem_thread_test(void)
{
	const int	n_thread = 100;
	const char	*sem_name = "semrace";
	pthread_t	*str_thread;
	t_stat		stat;

	stat.sem = sem_open(sem_name, O_CREAT | O_EXCL, 0444, 1);
	stat.status = 0;
	if (stat.sem == SEM_FAILED || sem_unlink(sem_name) == -1)
	{
		perror(sem_name);
		return ;
	}
	str_thread = malloc(sizeof(pthread_t) * n_thread);
	for (int i = 0; i < n_thread; i++)
		pthread_create(&str_thread[i], NULL, testthread, &stat);
	for (int i = 0; i < n_thread; i++)
		pthread_join(str_thread[i], NULL);
	printf("value: %ld\n", stat.status);
	printf("mean: %ld\n", stat.status / n_thread);
	free(str_thread);
	semaphore_report(sem_close, stat.sem);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		g_increment = 100;
	else
		g_increment = atoi(argv[1]);
	sem_thread_test();
}
