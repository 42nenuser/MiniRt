/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:34:38 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:54:18 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include <stdlib.h>

void	delete_all_spheres(t_sphere **head)
{
	t_sphere	*current;
	t_sphere	*next_node;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}

void	delete_all_cylinders(t_cylinder **head)
{
	t_cylinder	*current;
	t_cylinder	*next_node;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}

void	delete_all_planes(t_plane **head)
{
	t_plane	*current;
	t_plane	*next_node;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}

void	free_un(t_units *un)
{
	if (!un)
		return ;
	delete_all_cylinders(&(un->obj.cy));
	delete_all_spheres(&(un->obj.sp));
	delete_all_planes(&(un->obj.pl));
	free(un);
}
