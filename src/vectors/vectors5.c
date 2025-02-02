/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:57 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:47:45 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vectors.h"

float	clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_vec3	vec3_multiply_float(t_vec3 v, float scalar)
{
	return (vec3_create(v.r * scalar, v.g * scalar, v.b * scalar));
}

// Function to create a mat3 from three vec3    
t_mat3	mat3_create(t_vec3 t, t_vec3 b, t_vec3 n)
{
	t_mat3	matrix;
	int		i;

	i = 0;
	while (i < 3)
	{
		matrix.m[0][i] = (&t.r)[i];
		matrix.m[1][i] = (&b.r)[i];
		matrix.m[2][i] = (&n.r)[i];
		i++;
	}
	return (matrix);
}

// Function to transpose a t_mat3
t_mat3	mat3_transpose(t_mat3 m)
{
	t_mat3	transposed;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			transposed.m[j][i] = m.m[i][j];
			j++;
		}
		i++;
	}
	return (transposed);
}

float	dot_vec3(t_vec3 v1, t_vec3 v2)
{
	return (v1.r * v2.r + v1.g * v2.g + v1.b * v2.b);
}
