/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:20:52 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:04:44 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_s(char *s, int size, int n)
{
	s[size] = '\0';
	size--;
	while (size >= 0 && n != 0)
	{
		s[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		size;
	long	nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	size = ft_size(nb);
	s = (char *)malloc(size * sizeof(char ) + 1);
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	return (ft_s(s, size, nb));
}
