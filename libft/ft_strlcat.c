/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:52:35 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:06:26 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;
	size_t	j;

	if (!dst && dstsize == 0)
		return (0);
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	i = 0;
	j = dst_l;
	if (dstsize == 0 || dstsize <= dst_l)
		return (src_l + dstsize);
	while (src[i] != '\0' && i < dstsize - dst_l - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dst_l + src_l);
}
