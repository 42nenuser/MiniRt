/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FTPRINTF.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:48:02 by fhihi             #+#    #+#             */
/*   Updated: 2022/10/22 18:00:51 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putnbr_base(int n, char *base);
int	ft_putpointer(unsigned long nb);
int	ft_putunbr(unsigned int nb);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_hex(unsigned int n, char c);

#endif