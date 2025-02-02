/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:20:04 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:05:58 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char c)
{
	int				len;
	char			*base;
	int long long	nb;

	len = 0;
	nb = n;
	base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (nb < 16)
		len += ft_putchar(base[nb]);
	if (nb >= 16)
	{
		len += ft_putnbr_base(nb / 16, base);
		len += ft_putnbr_base(nb % 16, base);
	}
	return (len);
}
