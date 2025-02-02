/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:36:36 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/13 01:36:01 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

void	set_light(char **s, int len, t_units *un)
{
	if (len != 4)
		ft_error(un);
	un->lght.l.direction = normalize_vec3(set_point(s[0], un));
	un->lght.l.brightness = ft_atof(s[1]);
	un->lght.l.color = set_color(s[2], un);
}

void	set_camera(char **s, int len, t_units *un)
{
	if (len != 4)
		ft_error(un);
	un->cam.position = set_point(s[0], un);
	un->cam.direction = normalize_vec3(set_vec(s[1], un));
	un->cam.zoom = ft_atof(s[2]);
}

void	set_sphere(char **s, int len, t_units *un)
{
	t_sphere	*node;

	if (len != 4)
		ft_error(un);
	node = new_sphere(ft_atof(s[1]), set_point(s[0], un), set_color(s[2], un));
	add_sphere(&(un->obj.sp), node);
}

void	set_plane(char **s, int len, t_units *un)
{
	t_plane	*node;
	t_vec3	tmp;

	if (len != 4)
		ft_error(un);
	tmp = normalize_vec3(set_vec(s[1], un));
	node = new_plane(set_point(s[0], un), tmp, set_color(s[2], un));
	add_plane(&(un->obj.pl), node);
}

void	set_cylinder(char **s, int len, t_units *un)
{
	t_cylinder	*node;
	t_cyvar		var;

	if (len != 6)
		ft_error(un);
	var.position = set_point(s[0], un);
	var.nor = normalize_vec3(set_vec(s[1], un));
	var.diameter = ft_atof(s[2]);
	var.height = ft_atof(s[3]);
	var.color = set_color(s[4], un);
	node = new_cylinder(var);
	add_cylinder(&(un->obj.cy), node);
}
