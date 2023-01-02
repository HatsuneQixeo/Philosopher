/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:28:05 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/03 02:28:06 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

int	philosopher(char **argv);

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
		while (*++argv)
			printf("Exessive arguments: %s\n", *argv);
	}
	else
		return (philosopher(argv));
	return (1);
}