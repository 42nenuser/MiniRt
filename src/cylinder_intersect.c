/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:44:48 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:48:29 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

static int	intersectcaps(t_incy i, t_vec3 *sf, float *thit)
{
	float	tbottom;
	t_vec3	pbottom;
	float	ttop;
	t_vec3	ptop;

	tbottom = i.lrayorig.g / i.lraydir.g;
	pbottom = vec3_add(i.lrayorig, vec3_multiply_float(i.lraydir, tbottom));
	if (tbottom > 0.0 && pbottom.r * pbottom.r + pbottom.b * pbottom.b
		<= (i.cylinder.diameter * 0.5) * (i.cylinder.diameter * 0.5))
	{
		*thit = tbottom;
		*sf = vec3_create(0.0, -1.0, 0.0);
		return (1);
	}
	ttop = (i.cylinder.height - i.lrayorig.g) / i.lraydir.g;
	ptop = vec3_add(i.lrayorig, vec3_multiply_float(i.lraydir, ttop));
	if (ttop > 0.0 && ptop.r * ptop.r + ptop.b * ptop.b
		<= (i.cylinder.diameter * 0.5) * (i.cylinder.diameter * 0.5))
	{
		*thit = ttop;
		*sf = vec3_create(0.0, 1.0, 0.0);
		return (1);
	}
	return (0);
}

static t_var1	get_values(t_vec3 rayorig, t_vec3 raydir, t_cylinder cylinder)
{
	t_var1	v;
	t_mat3	lrotmat;
	t_vec3	lrayorig;
	t_vec3	lraydir;

	lrotmat = rotationtoy(cylinder.axis);
	lrayorig = mat3_multiply_vec3(mat3_transpose(lrotmat), \
vec3_subtract(rayorig, cylinder.position));
	lraydir = mat3_multiply_vec3(mat3_transpose(lrotmat), raydir);
	v.r = cylinder.diameter * 0.5;
	v.a = lraydir.r * lraydir.r + lraydir.b * lraydir.b;
	v.b = 2.0 * (lrayorig.r * lraydir.r + lrayorig.b * lraydir.b);
	v.c = lrayorig.r * lrayorig.r + lrayorig.b * lrayorig.b - v.r * v.r;
	return (v);
}

int	intersect(t_vec3 rayorig, t_vec3 raydir, t_vec3 *sf, t_cylinder cylinder)
{
	t_incy	i;
	t_var1	v;
	t_vec3	phit;

	i.cylinder = cylinder;
	i.lrotmat = rotationtoy(cylinder.axis);
	i.lrayorig = mat3_multiply_vec3(mat3_transpose(i.lrotmat), \
vec3_subtract(rayorig, cylinder.position));
	i.lraydir = mat3_multiply_vec3(mat3_transpose(i.lrotmat), raydir);
	v = get_values(rayorig, raydir, cylinder);
	if (solvequadratic(&v))
	{
		v.t = fmin(v.t0, v.t1);
		phit = vec3_add(i.lrayorig, vec3_multiply_float(i.lraydir, v.t));
		if (phit.g < 0.0 || phit.g > cylinder.height)
		{
			if (intersectcaps(i, sf, &v.t))
				return (1);
			return (0);
		}
		*sf = normalize_vec3(mat3_multiply_vec3(i.lrotmat, \
vec3_create(phit.r, 0.0, phit.b)));
		return (1);
	}
	return (0);
}
