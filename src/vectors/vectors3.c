/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:47 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:51:06 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vectors.h"

t_vec3	mat3_mul_vec3(t_mat3 m, t_vec3 v)
{
	t_vec3	result;

	result.r = m.m[0][0] * v.r + m.m[0][1] * v.g + m.m[0][2] * v.b;
	result.g = m.m[1][0] * v.r + m.m[1][1] * v.g + m.m[1][2] * v.b;
	result.b = m.m[2][0] * v.r + m.m[2][1] * v.g + m.m[2][2] * v.b;
	return (result);
}

t_vec3	vec3_negate(t_vec3 v)
{
	t_vec3	result;

	result.r = -v.r;
	result.g = -v.g;
	result.b = -v.b;
	return (result);
}

t_mat3	mat3_add(t_mat3 m1, t_mat3 m2)
{
	t_mat3	result;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

t_mat3	mat3_multiply_scalar(t_mat3 m, float scalar)
{
	t_mat3	result;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			result.m[i][j] = m.m[i][j] * scalar;
			j++;
		}
		i++;
	}
	return (result);
}

t_mat3	mat3_multiply(t_mat3 m1, t_mat3 m2)
{
	t_mat3	result;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			result.m[i][j] = 0.0;
			while (k < 3)
			{
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}
