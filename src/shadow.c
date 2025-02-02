/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:46:37 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:03:08 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	radians(double degrees)
{
	return (degrees * M_PI / 180.0);
}

int	isinshadow(t_units *un, t_vec3 point, t_vec3 tolight)
{
	t_vec3		sf;
	t_sphere	*sp;
	t_cylinder	*cy;
	float		thit;
	t_ray		r;

	r.o = vec3_add(point, vec3_multiply_float(tolight, 1e-4));
	r.d = tolight;
	sp = un->obj.sp;
	cy = un->obj.cy;
	while (cy)
	{
		if (intersect(vec3_add(point, vec3_multiply_float(tolight, 1e-4)), \
tolight, &sf, *cy))
			return (1);
		cy = cy->next;
	}
	while (sp)
	{
		if (intersect_sphere(*sp, r, &sf, &thit))
			if (thit > 1e-4)
				return (1);
		sp = sp->next;
	}
	return (0);
}
