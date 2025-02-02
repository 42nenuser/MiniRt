/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:35:05 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/07 19:52:11 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

void	add_plane(t_plane **list, t_plane *new)
{
	t_plane	*current;

	if (!*list)
		*list = new;
	else
	{
		current = last_plane(*list);
		current->next = new;
	}
}

t_cylinder	*new_cylinder(t_cyvar var)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->color = var.color;
	cy->position = var.position;
	cy->height = var.height;
	cy->diameter = var.diameter;
	cy->axis = var.nor;
	cy->next = NULL;
	return (cy);
}

t_cylinder	*last_cylinder(t_cylinder *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	add_cylinder(t_cylinder **list, t_cylinder *new)
{
	t_cylinder	*current;

	if (!*list)
		*list = new;
	else
	{
		current = last_cylinder(*list);
		current->next = new;
	}
}
