/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:03:36 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/07 19:45:32 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atof.h"

// Handle exponent notation
double	ft_atof_part2(int ex, int exsign)
{
	double	poweroften;

	poweroften = 1.0;
	while (ex != 0)
	{
		if (exsign == 1)
			poweroften *= 10.0;
		else
			poweroften *= 1.0 / 10.0;
		ex--;
	}
	return (poweroften);
}

// Apply sign, exponent, and convert to double
double	ft_atof_part1(char *str, int i, int sign, double result)
{
	int		exponent;
	int		exponentsign;

	exponent = 0;
	exponentsign = 1;
	if (str[i] == 'e' || str[i] == 'E') 
	{
		i++;
		if (str[i] == '-')
		{
			exponentsign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			exponent = exponent * 10 + (str[i++] - '0');
	}
	return (result * ft_atof_part2(exponent, exponentsign) * sign);
}

double	ft_atof(char *str)
{
	t_var	var;

	var.i = 0;
	var.result = 0.0;
	var.sign = 1;
	var.fraction = 0.1;
	if (str[var.i] == '-' || str[var.i] == '+')
	{
		if (str[var.i] == '-')
			var.sign = -1;
		var.i++;
	}
	while (ft_isdigit(str[var.i]))
		var.result = var.result * 10 + (str[var.i++] - '0');
	if (str[var.i] == '.')
	{
		var.i++;
		while (ft_isdigit(str[var.i]))
		{
			var.result += (str[var.i++] - '0') * var.fraction;
			var.fraction *= 0.1;
		}
	}
	return (ft_atof_part1(str, var.i, var.sign, var.result));
}
