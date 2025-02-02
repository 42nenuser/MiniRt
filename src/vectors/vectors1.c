/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:58 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:46:30 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vectors.h"

t_mat3	rotationtoy(t_vec3 dir)
{
	t_mat3	vmat;
	t_mat3	identity;
	t_mat3	temp;
	t_temp	tmp;

	tmp.v1 = cross_vec3(dir, vec3_create(0.0, 1.0, 0.0)); 
	tmp.f1 = vec3_length(tmp.v1);
	tmp.f2 = dot_vec3(dir, vec3_create(0.0, 1.0, 0.0));
	vmat = mat3_create(vec3_create(0, -tmp.v1.b, tmp.v1.g), \
vec3_create(tmp.v1.b, 0, -tmp.v1.r), vec3_create(-tmp.v1.g, tmp.v1.r, 0));
	identity = mat3_create(vec3_create(1.0, 0.0, 0.0), \
vec3_create(0.0, 1.0, 0.0), vec3_create(0.0, 0.0, 1.0));
	tmp.f3 = (1.0 - tmp.f2) / (tmp.f1 * tmp.f1);
	temp = mat3_add(identity, mat3_add(vmat, \
mat3_multiply_scalar(mat3_multiply(vmat, vmat), tmp.f3)));
	return (temp);
}

t_vec3	mat3_multiply_vec3(t_mat3 m, t_vec3 v)
{
	t_vec3	result;

	result.r = m.m[0][0] * v.r + m.m[0][1] * v.g + m.m[0][2] * v.b;
	result.g = m.m[1][0] * v.r + m.m[1][1] * v.g + m.m[1][2] * v.b;
	result.b = m.m[2][0] * v.r + m.m[2][1] * v.g + m.m[2][2] * v.b;
	return (result);
}

t_vec2	vec2_create(float x, float y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2	vec2_divide_vec(t_vec2 a, t_vec2 b)
{
	if (b.x != 0.0 && b.y != 0.0)
		return (vec2_create(a.x / b.x, a.y / b.y));
	else
		return (vec2_create(0, 0));
}

t_vec2	vec2_subtract_scalar(t_vec2 a, float scalar)
{
	t_vec2	result;

	result.x = a.x - scalar;
	result.y = a.y - scalar;
	return (result);
}
