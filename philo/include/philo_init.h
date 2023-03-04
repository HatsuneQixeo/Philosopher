/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INIT_H
# define PHILO_INIT_H

// malloc, free
# include <stdlib.h>
# include "philo.h"

# define NOPHL	"number_of_philosophers"
# define TDIE	"time_to_die"
# define TEAT	"time_to_eat"
# define TSLP	"time_to_sleep"
# define NOFIN	"number_of_times_each_philosopher_must_eat"

void	philosopher(t_table table);

// libft_ft
int		ft_strisnumeric(const char *str);
int		ft_atoi(const char *str);

// Mutex
int		default_mutex_init(pthread_mutex_t *mutex);

// World end table
int		philo_evaluate(char **argv);
t_table	world_end_table(char **argv);

// philo_for_ft
void	iter_init_fork(unsigned int i, t_table *table,
			void *ptr_forks, void *ptr_null);
void	iter_init_philo(unsigned int i, t_table *table,
			void *ptr_philo, void *ptr_forks);
void	iter_jointhread(unsigned int i, t_table *table,
			void *ptr_thread, void *ptr_null);
void	iter_clean(unsigned int i, t_table *table,
			void *ptr_philo, void *ptr_null);
// Arrival
void	iter_batch_odd(unsigned int i, t_table *table,
			void *ptr_thread, void *ptr_philo);
void	iter_batch_even(unsigned int i, t_table *table,
			void *ptr_thread, void *ptr_philo);

// Simulation
void	*philo_simulation(void *ptr);
// Kill 1
void	philo_justdie(t_table *table);

// Monitor
void	philo_monitor_thread(t_philo *str_philo);

#endif
