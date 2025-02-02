/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:45:34 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:06:14 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	i1;
	int	count;

	i = 0;
	i1 = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && i1 == 0)
		{
			count++;
			i1 = 1;
		}
		else if (s[i] == c)
			i1 = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i[3];

	if (!s)
		return (NULL);
	new = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	i[2] = -1;
	while (i[0] <= (int)ft_strlen(s))
	{
		if ((s[i[0]] != c || s[i[0]] == '\0') && i[2] < 0)
			i[2] = i[0];
		else if ((s[i[0]] == c || s[i[0]] == '\0') && i[2] >= 0)
		{
			new[i[1]++] = ft_substr(s, i[2], i[0] - i[2]);
			i[2] = -1;
		}
		i[0]++;
	}
	new[i[1]] = NULL;
	return (new);
}
