/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:17 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/08 20:57:07 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INIT_H
# define PHILO_INIT_H

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

sem_t	*ft_sem_renew(const char *name, int permission, int amount);

int		philo_evaluate(char **argv);
t_table	world_end_table(char **argv);
// Simulation
void	*philo_simulation(void *ptr);

#endif
