/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:46:59 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:05:54 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int n, char *base)
{
	long	nb;
	int		bl;
	int		len;

	nb = n;
	bl = 0;
	len = 0;
	while (base[bl])
		bl++;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb < bl)
		len += ft_putchar(base[nb]);
	if (nb >= bl)
	{
		len += ft_putnbr_base(nb / bl, base);
		len += ft_putnbr_base(nb % bl, base);
	}
	return (len);
}
