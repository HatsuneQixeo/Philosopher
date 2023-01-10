// #include <pthread.h>
// #include <unistd.h>
// #include <stdio.h>

// #define THREAD_AMOUNT	3
// #define MS				1000

// pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

// void	*threading(void *ptr)
// {
// 	int	nbr = (int)ptr;

// 	pthread_mutex_lock(&mutex);
// 	printf("%d sleeping\n", nbr);
// 	usleep(nbr * MS * MS);
// 	printf("%d wokeup\n", nbr);
// 	pthread_mutex_unlock(&mutex);
// 	return (NULL);
// }

// int	main(void)
// {
// 	pthread_t	thread[THREAD_AMOUNT];

// 	for (int i = 0; i < THREAD_AMOUNT; i++)
// 		pthread_create(&thread[i], NULL, threading, (void *)(long)i + 1);
// 	for (int i = 0; i < THREAD_AMOUNT; i++)
// 		pthread_join(thread[i], NULL);
// }
