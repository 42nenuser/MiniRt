/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:36:12 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:50:53 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

void	check_cordinats(char **s, t_units *un)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i != 3)
		ft_error(un);
}

t_vec3	set_point(char *s, t_units *un)
{
	char	**tmp;
	t_vec3	point;

	tmp = ft_split(s, ',');
	check_cordinats(tmp, un);
	point.r = ft_atof(tmp[0]);
	point.g = ft_atof(tmp[1]);
	point.b = ft_atof(tmp[2]);
	free_arr(tmp);
	return (point);
}

t_vec3	set_color(char *s, t_units *un)
{
	char	**tmp;
	t_vec3	color;

	tmp = ft_split(s, ',');
	check_cordinats(tmp, un);
	color.r = ft_atof(tmp[0]) / 255.99;
	color.g = ft_atof(tmp[1]) / 255.99;
	color.b = ft_atof(tmp[2]) / 255.99;
	free_arr(tmp);
	return (color);
}

t_vec3	set_vec(char *s, t_units *un)
{
	char	**tmp;
	t_vec3	vec;

	tmp = ft_split(s, ',');
	check_cordinats(tmp, un);
	vec.r = ft_atof(tmp[0]);
	vec.g = ft_atof(tmp[1]);
	vec.b = ft_atof(tmp[2]);
	free_arr(tmp);
	return (vec);
}
