/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:39:11 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:54:32 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"
#include "fcntl.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	check_open(char *file, t_units *un)
{
	int		fd;
	char	**tmp;

	if (!ft_strnstr(file, ".", ft_strlen(file)))
		ft_error(un);
	tmp = ft_split(file, '.');
	if (tmp[1] && ft_strncmp(tmp[1], "rt", 3))
	{
		free_arr(tmp);
		ft_error(un);
	}
	fd = open(file, O_RDONLY);
	if ((fd) == -1)
		ft_error(un);
	return (fd);
}

int	check_id(char *s)
{
	if (!ft_strncmp(s, "A", 2))
		return (A);
	if (!ft_strncmp(s, "L", 2))
		return (L);
	if (!ft_strncmp(s, "C", 2))
		return (C);
	if (!ft_strncmp(s, "pl", 3))
		return (PL);
	if (!ft_strncmp(s, "sp", 3))
		return (SP);
	if (!ft_strncmp(s, "cy", 3))
		return (CY);
	return (0);
}

void	set_ambiant(char **s, int len, t_units *un)
{
	if (len != 3)
		ft_error(un);
	un->lght.al.ratio = ft_atof(s[0]);
	un->lght.al.color = vec3_multiply_float(set_color(s[1], un), \
un->lght.al.ratio);
}

void	ft_set(char **s, int len, t_units **un)
{
	int	id;

	id = check_id(s[0]);
	s++;
	if (id == A)
		set_ambiant(s, len, *un);
	else if (id == L)
		set_light(s, len, *un);
	else if (id == C)
		set_camera(s, len, *un);
	else if (id == SP)
		set_sphere(s, len, *un);
	else if (id == PL)
		set_plane(s, len, *un);
	else if (id == CY)
		set_cylinder(s, len, *un);
}
