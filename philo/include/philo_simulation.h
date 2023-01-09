/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 13:58:22 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SIMULATION_H
# define PHILO_SIMULATION_H

// usleep
# include <unistd.h>
# include "philo.h"

# define MS			1000
# define WAIT		250
# define GETFORK	"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DEATH		"died"
# define DIED		-1

void	philo_do(t_philo *philo, int ms);
void	philo_think(t_philo *philo);
void	philo_log(t_philo *philo, const char *action);

// Utils
long	philo_time(t_table *table);
void	stat_set(t_stat *stat, int set);
int		stat_get(t_stat *stat);

#endif
