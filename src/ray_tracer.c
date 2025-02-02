/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:17:26 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/13 04:31:46 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

// Function to solve a quadratic equation given a, b, and c coefficients
int	solvequadratic(t_var1 *v)
{
	float	disc;

	disc = v->b * v->b - 4. * v->a * v->c;
	if (disc < 0.)
		return (0);
	if (disc == 0.)
	{
		v->t0 = -v->b / (2. * v->a);
		v->t1 = -v->b / (2. * v->a);
		return (1);
	}
	v->t0 = (-v->b + sqrt(disc)) / (2. * v->a);
	v->t1 = (-v->b - sqrt(disc)) / (2. * v->a);
	return (1);
}

static t_vec3	raytrace_part2(t_vec3 dir, t_units *un)
{
	t_vec3		phit;
	t_plane		*pl;
	t_vec3		col;

	pl = un->obj.pl;
	while (pl)
	{
		if (intersect_plane(un, dir, &phit))
		{
			col = un->obj.pl->color;
			if (isinshadow(un, phit, vec3_negate(un->lght.l.direction)))
				col = vec3_multiply_float(col, un->lght.l.brightness);
			return (vec3_multiply_float(col, un->lght.l.brightness)); 
		}
		pl = pl->next;
	}
	return (vec3_create(0., 0., 0.));
}

static	float	get_coeff(float coeff)
{
	if (coeff < 0)
		return (0);
	return (coeff);
}

static t_vec3	raytrace_part1(t_vec3 direction, t_units *un)
{
	float		thit;
	float		coeff;
	t_vec3		sf;
	t_sphere	*sp;
	t_ray		r;

	r.o = un->cam.position;
	r.d = direction;
	sp = un->obj.sp;
	while (sp)
	{
		if (intersect_sphere(*sp, r, &sf, &thit))
		{
			coeff = -dot_vec3(un->lght.l.direction, sf);
			coeff = get_coeff(coeff);
			return (vec3_multiply_float(vec3_multiply_float(sp->color, coeff), \
un->lght.l.brightness));
		}
		sp = sp->next;
	}
	return (raytrace_part2(direction, un));
}

t_vec3	raytrace(t_vec3 direction, t_units *un)
{
	t_vec3		sf;
	float		thit;
	t_cylinder	*cy;
	t_vec3		col;
	float		coeff;

	cy = un->obj.cy;
	while (cy)
	{
		if (intersect(un->cam.position, direction, &sf, *cy))
		{
			coeff = -dot_vec3(un->lght.l.direction, sf);
			coeff = get_coeff(coeff);
			col = vec3_multiply_float(cy->color, coeff);
			return (vec3_multiply_float(col, un->lght.l.brightness));
		}
		cy = cy->next;
	}
	return (raytrace_part1(direction, un));
}
