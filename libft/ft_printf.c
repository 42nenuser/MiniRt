/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:57 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/11 21:05:26 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	types(va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, int), c));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, int), c));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putpointer(va_arg(args, unsigned long)) + 2);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += types(args, s[i]);
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
