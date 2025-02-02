/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:44:55 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:49:39 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

int	intersect_sphere(t_sphere sphere, t_ray r, t_vec3 *sf, float *thit)
{
	t_vec3	l;
	t_vec3	phit;
	t_var1	v;

	l = vec3_subtract(r.o, sphere.position);
	v.a = dot_vec3(r.d, r.d);
	v.b = 2.0 * dot_vec3(r.d, l);
	v.c = dot_vec3(l, l) - pow(sphere.radius, 2.0);
	if (solvequadratic(&v))
	{
		*thit = v.t0;
		if (v.t1 < v.t0)
			*thit = v.t1;
		phit = vec3_add(r.o, vec3_multiply_scalar(r.d, *thit));
		*sf = normalize_vec3(vec3_subtract(phit, sphere.position));
		return (1);
	}
	return (0);
}
