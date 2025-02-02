/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:18:18 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:01:48 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"

t_sphere	*new_sphere(float r, t_vec3 center, t_vec3 color)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->color = color;
	sp->position = center;
	sp->radius = r;
	sp->next = NULL;
	return (sp);
}

t_sphere	*last_sphere(t_sphere *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	add_sphere(t_sphere **list, t_sphere *new)
{
	t_sphere	*current;

	if (!*list)
		*list = new;
	else
	{
		current = last_sphere(*list);
		current->next = new;
	}
}

t_plane	*new_plane(t_vec3 point, t_vec3 nor, t_vec3 color)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->color = color;
	pl->normal = nor;
	pl->point = point;
	pl->next = NULL;
	return (pl);
}

t_plane	*last_plane(t_plane *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
