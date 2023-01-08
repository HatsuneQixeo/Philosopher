/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:19:18 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/08 20:57:06 by hqixeo           ###   ########.fr       */
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

int		philosopher(char **argv);

// libft_ft
int		ft_strisnumeric(const char *str);
int		ft_atoi(const char *str);
int		loop_static(int *nbr);
int		loop_increment(int *nbr);

// Mutex
int		default_mutex_init(pthread_mutex_t *mutex);

// philo_for_ft
typedef void	(*t_iter)(int i, t_table *table, void *arg1, void *arg2);
void	init_fork(int i, t_table *table, void *ptr_forks, void *ptr_null);
void	init_philo(int i, t_table *table, void *ptr_philo, void *ptr_forks);
void	sim_begin(int i, t_table *table, void *ptr_thread, void *ptr_philo);
void	sim_end(int i, t_table *table, void *ptr_thread, void *ptr_null);
void	destroy_forks(int i, t_table *table, void *ptr_forks, void *ptr_null);

// Simulation
void	*ft_simulation(void *ptr);

#endif
