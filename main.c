/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:43:21 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/12 23:29:16 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vectors.h"

// Clamp the color components to the range [0, 1]
// adding ambiant light to final color
// Convert the color to RGBA format
int	compute_color(t_vec3 col, t_vec3 al_color)
{
	t_vec4	fragcolor;
	int		color;

	col.r = fmax(0.0, fmin(col.r, 1.0));
	col.g = fmax(0.0, fmin(col.g, 1.0));
	col.b = fmax(0.0, fmin(col.b, 1.0));
	vec3_add(col, al_color);
	fragcolor = vec4_create(col.r, col.g, col.b, 0.0f);
	color = vec4_to_color(fragcolor);
	return (color);
}

// Create an "up" vector
// Create a "right" vector
// Recalculate the "up" vector
// Apply rotation
t_vec3	rotated_ray_dir(t_vec3 cam_dir, t_vec3 initial_ray_dir)
{
	t_vec3	term1;
	t_vec3	term2;
	t_vec3	term3;
	t_vec3	right;
	t_vec3	up;

	up = vec3_create(0.0, 1.0, 0.0);
	right = normalize_vec3(cross_vec3(cam_dir, up));
	up = normalize_vec3(cross_vec3(right, cam_dir));
	term1 = vec3_multiply_scalar(right, initial_ray_dir.r);
	term2 = vec3_multiply_scalar(up, initial_ray_dir.g);
	term3 = vec3_multiply_scalar(cam_dir, initial_ray_dir.b);
	return (vec3_add(vec3_add(term1, term2), term3));
}

t_vec3	set_uv(t_vec2 fragcoord, t_vec2 iresolution, float tanfov)
{
	t_vec2	uv;
	t_vec3	iraydir;

	uv = vec2_divide_vec(fragcoord, iresolution);
	uv = vec2_subtract_scalar(uv, 0.5f);
	uv.x *= iresolution.x / iresolution.y;
	iraydir = normalize_vec3(vec3_create(uv.x * tanfov, uv.y * tanfov, -1.0));
	return (iraydir);
}

// Render the image to the window
// For every pixel on the screen
void	rendering(t_vars *vars)
{
	t_rend	v;
	int		i;
	int		j;
	float	tanfov;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			tanfov = tan(radians(vars->un->cam.zoom) * 0.5);
			v.fragcoord = vec2_create((float)i, (float)j);
			v.iresolution = vec2_create((float)WIDTH, (float)HEIGHT);
			v.iraydir = set_uv(v.fragcoord, v.iresolution, tanfov);
			v.col = raytrace(rotated_ray_dir(vars->un->cam.direction, \
v.iraydir), vars->un);
			my_mlx_pixel_put(&vars->img, i, j, \
compute_color(v.col, vars->un->lght.al.color));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int ac, char *av[])
{
	t_vars	vars;
	t_units	*un;

	un = NULL;
	if (ac != 2)
		ft_error(un);
	un = parse_file(av[1]);
	vars.un = un;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "miniRt");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
&vars.img.line_length, &vars.img.endian);
	vars.mouse_x = WIDTH / 2;
	vars.mouse_y = HEIGHT / 2;
	rendering(&vars);
	mlx_hook(vars.win, 2, 1L << 0, closing, &vars);
	mlx_hook(vars.win, 17, 0, closingesc, &vars);
	free_un(un);
	mlx_loop(vars.mlx);
}
