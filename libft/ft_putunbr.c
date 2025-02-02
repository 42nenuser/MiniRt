/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:31:17 by fhihi             #+#    #+#             */
/*   Updated: 2022/10/23 15:36:26 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10)
		len += ft_putchar(nb + '0');
	if (nb >= 10)
	{
		len += ft_putunbr(nb / 10);
		len += ft_putunbr(nb % 10);
	}
	return (len);
}
