/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:52:24 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:05:16 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p1;
	const char	*p2;

	i = 0;
	p1 = dst;
	p2 = src;
	if (p1 == 0 && p2 == 0)
		return (NULL);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}
