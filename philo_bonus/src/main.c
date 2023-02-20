/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:50:03 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/13 17:10:43 by hqixeo           ###   ########.fr       */
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
	else
		return (philosopher(argv));
	return (1);
}
