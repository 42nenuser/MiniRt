/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:51:37 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:04:22 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_result(const char *str, int sign, long rslt, int pos)
{
	while (ft_isdigit(str[pos]))
	{
		rslt = rslt * 10 + str[pos++] - '0';
		if (rslt < 0)
		{
			if (sign != -1)
				return (-1);
			else
				return (0);
		}
	}
	return (rslt);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	r = ft_result(str, s, r, i);
	return (r * s);
}
