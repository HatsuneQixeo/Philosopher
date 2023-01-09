/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:22 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/09 22:08:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Field: [required] {optional}\n"
			"Note: time is calculated in miliseconds\n"
			"./philo [%s] [%s] [%s] [%s] {%s}\n",
			NOPHL, TDIE, TEAT, TSLP, NOFIN);
	}
	else if (argc > 6)
	{
		argv += 5;
		while (*++argv != NULL)
			printf("Exessive arguments: %s\n", *argv);
	}
	else if (philo_evaluate(argv))
	{
		philosopher(world_end_table(argv));
		return (0);
	}
	return (1);
}
