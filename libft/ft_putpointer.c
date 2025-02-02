/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:25:32 by fhihi             #+#    #+#             */
/*   Updated: 2022/10/23 15:29:58 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long nb)
{
	int		len;

	len = 0;
	if (nb < 16)
		len += ft_putchar("0123456789abcdef"[nb]);
	if (nb >= 16)
	{
		len += ft_putpointer(nb / 16);
		len += ft_putpointer(nb % 16);
	}
	return (len);
}
