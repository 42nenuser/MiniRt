/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:53:33 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:47:25 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vectors.h"

t_vec3	vec3_divide_scalar(t_vec3 v, float scalar)
{
	t_vec3	result;

	result.r = v.r / scalar;
	result.g = v.g / scalar;
	result.b = v.b / scalar;
	return (result);
}

t_vec3	vec3_subtract(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.r = a.r - b.r;
	result.g = a.g - b.g;
	result.b = a.b - b.b;
	return (result);
}

t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	result;

	result.r = vec1.r + vec2.r;
	result.g = vec1.g + vec2.g;
	result.b = vec1.b + vec2.b;
	return (result);
}

t_vec3	normalize_vec3(t_vec3 x)
{
	float	len;

	len = vec3_length(x);
	return (vec3_divide_scalar(x, len));
}

float	vec3_length(t_vec3 v)
{
	return (sqrt(v.r * v.r + v.g * v.g + v.b * v.b));
}
