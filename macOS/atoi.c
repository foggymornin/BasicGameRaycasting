/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafajat <mafajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:53:35 by mafajat           #+#    #+#             */
/*   Updated: 2021/02/19 10:13:25 by mafajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi(const char *str)
{
	int nb;
	int n;
	int s;

	s = 1;
	n = 0;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (s > 0 && nb < 0)
			return (-1);
		if (s < 0 && nb < 0)
			return (0);
		n = *str - '0';
		nb = 10 * nb + n;
		str++;
	}
	return (nb * s);
}