/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:29:51 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 02:29:54 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SIMULATION_H
# define PHILO_SIMULATION_H

//write, usleep
# include <unistd.h>
# include "philo.h"

# define MS			1000
# define WAIT		250
# define GETFORK	"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DEATH		"died"

void	philo_do(t_philo *philo, int time);
void	philo_think(t_philo *philo);
long	philo_time(t_table *table);
void	stat_set(t_stat *stat, int set);
int		stat_get(t_stat *stat);
void	philo_log(t_philo *philo, const char *action);

#endif
