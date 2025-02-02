/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:43:05 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:06:44 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len;
	int	size;

	i = 0;
	if (!s1)
		return (NULL);
	while ((int)ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i == (int)ft_strlen(s1))
		return (ft_substr(s1, i, 0));
	len = ft_strlen(s1) - 1;
	while ((int)ft_strchr(set, s1[len]))
		len--;
	size = len - i + 1;
	return (ft_substr(s1, i, size));
}
