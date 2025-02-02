/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:45:52 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 20:48:42 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

int	intersect_plane(t_units *un, t_vec3 dir, t_vec3 *hit)
{
	float	denom;
	float	ttemp;

	denom = dot_vec3(un->obj.pl->normal, dir);
	if (fabs(denom) < 0.0001)
		return (0);
	ttemp = dot_vec3(vec3_subtract(un->obj.pl->point, un->cam.position), \
un->obj.pl->normal) / denom;
	if (ttemp >= 0.)
	{
		*hit = vec3_add(un->cam.position, vec3_multiply_float(dir, ttemp));
		return (1);
	}
	return (0);
}
