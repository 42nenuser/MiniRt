/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:42 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:46:55 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vectors.h"

t_vec3	vec3_create(float r, float g, float b)
{
	t_vec3	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_vec4	vec4_create(float x, float y, float z, float w)
{
	t_vec4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

int	vec4_to_color(t_vec4 color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (int)(color.x * 255);
	g = (int)(color.y * 255);
	b = (int)(color.z * 255);
	a = (int)(color.w * 255);
	return ((a << 24) + (r << 16) + (g << 8) + b);
}

t_vec3	vec3_multiply_scalar(t_vec3 v, float scalar)
{
	v.r *= scalar;
	v.g *= scalar;
	v.b *= scalar;
	return (v);
}

t_vec3	cross_vec3(t_vec3 x, t_vec3 y)
{
	t_vec3	result;

	result.r = x.g * y.b - x.b * y.g;
	result.g = x.b * y.r - x.r * y.b;
	result.b = x.r * y.g - x.g * y.r;
	return (result);
}
