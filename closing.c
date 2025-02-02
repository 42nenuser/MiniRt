/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:06:57 by yait-oul          #+#    #+#             */
/*   Updated: 2023/09/12 23:08:31 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vectors.h"

int	closing(int keycode, void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	closingesc(void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
