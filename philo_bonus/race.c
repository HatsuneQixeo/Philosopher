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

// #include <philo.h>
// #include <philo_simulation.h>
// #include <philo_init.h>

// #define THREAD_SIZE	5
// #define SEM_NAME	"semmiku"

// void	*testloop(void *arg)
// {
// 	t_stat	*miku;

// 	miku = arg;
// 	// semaphore_report
// 	for (int i = 0; i < UINT16_MAX; i++)
// 		stat_set(miku, i);
// 	printf("%p Thread\n", miku->sem);
// 	return (NULL);
// }

// int	main(void)
// {
// 	pthread_t	str_thread[THREAD_SIZE];
// 	t_stat		stat;

// 	if (sem_unlink(SEM_NAME) == -1)
// 		perror("Unlink");
// 	stat.sem = sem_open(SEM_NAME, O_CREAT, 0660, 01);
// 	if (stat.sem == SEM_FAILED)
// 	{
// 		perror("Open");
// 		return (1);
// 	}
// 	printf("%p Main\n", stat.sem);
// 	for (int i = 0; i < THREAD_SIZE; i++)
// 		pthread_create(&str_thread[i], NULL, testloop, &stat);
// 	for (int i = 0; i < THREAD_SIZE; i++)
// 		pthread_join(str_thread[i], NULL);
// 	semaphore_report(sem_close, stat.sem);
// 	if (sem_unlink("MIKU") == -1)
// 		perror("Miss you");
// }
