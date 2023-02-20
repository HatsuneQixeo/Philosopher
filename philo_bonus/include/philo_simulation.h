/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:17 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:44 by hqixeo           ###   ########.fr       */
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

int		philo_isalive(t_philo *philo, long current);
void	philo_do(t_philo *philo, int ms);
void	philo_log(t_philo *philo, const char *action);

// Utils
long	philo_time(t_table *table);

void	stat_set(t_stat *stat, long set);
long	stat_get(t_stat *stat);
#endif
