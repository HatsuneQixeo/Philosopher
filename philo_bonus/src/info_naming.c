/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_naming.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:43 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/04 10:52:41 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"
#define INFONAME	"philoinfo_"

static int	ft_nbrsize(int nbr)
{
	int	digit;

	digit = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}

static char	*ft_semname(int id)
{
	char	*str;
	size_t	i_strcpy;
	int		len_nbr;

	len_nbr = ft_nbrsize(id);
	str = malloc(sizeof(INFONAME) + len_nbr + 1);
	str[sizeof(INFONAME) + len_nbr] = '\0';
	i_strcpy = -1;
	while (++i_strcpy < sizeof(INFONAME))
		str[i_strcpy] = INFONAME[i_strcpy];
	while (len_nbr--)
	{
		str[sizeof(INFONAME) + len_nbr] = (id % 10) + '0';
		id /= 10;
	}
	return (str);
}

t_info	default_info_init(int id)
{
	t_info	info;
	char	*name;

	info.id = id;
	info.eaten = 0;
	name = ft_semname(id);
	info.time_lastmeal.sem = ft_sem_renew(name, 0660, 01);
	free(name);
	return (info);
}
