/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:43:32 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/07 19:54:16 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOF_H
# define ATOF_H

# include "../libft/libft.h"

typedef struct s_var
{
	int		i;
	double	result;
	double	fraction;
	int		sign;
}			t_var;

#endif