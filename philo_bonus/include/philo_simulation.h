/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:17 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:42 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SIMULATION_H
# define PHILO_SIMULATION_H

# include "philo.h"

# define MS			1000
# define WAIT		250
# define GETFORK	"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DEATH		"died"

int		philo_isalive(t_philo *philo, time_t current);
void	philo_do(t_philo *philo, int ms);
void	philo_log(t_philo *philo, const char *action);

// Utils
time_t	philo_time(t_table *table);

void	time_set(t_time *time);
time_t	time_get(t_time *time, struct timeval start);
#endif
