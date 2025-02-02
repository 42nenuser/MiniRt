/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:21:18 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:04:57 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!del || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		ft_lstdelone(*lst, del);
		current = current->next;
		*lst = current;
	}
}
