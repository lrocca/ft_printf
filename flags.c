/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:22:30 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/11 12:35:40 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	justify(void)
{
	if (*g_var.format == '-')
	{
		g_var.justify = 1;
		g_var.format++;
		return (1);
	}
	return (0);
}

static int	padding(void)
{
	if (*g_var.format == '0')
	{
		g_var.padding = '0';
		g_var.format++;
		return (1);
	}
	return (0);
}

static int	width(void)
{
	if (*g_var.format == '*')
	{
		g_var.width = va_arg(g_var.args, int);
		if (g_var.width < 0)
		{
			g_var.justify = 1;
			g_var.width *= -1;
		}
		g_var.format++;
		return (1);
	}
	else if (ft_isdigit(*g_var.format))
	{
		g_var.width = ft_atoi(g_var.format);
		while (ft_isdigit(*g_var.format))
			g_var.format++;
		return (1);
	}
	return (0);
}

static int	precision(void)
{
	if (*g_var.format == '.')
	{
		g_var.format++;
		g_var.precision = 0;
		if (*g_var.format == '*')
		{
			g_var.precision = va_arg(g_var.args, int);
			g_var.format++;
			return (1);
		}
		else if (ft_isdigit(*g_var.format))
		{
			g_var.precision = ft_atoi(g_var.format);
			while (ft_isdigit(*g_var.format))
				g_var.format++;
			return (1);
		}
	}
	return (0);
}

void		flags(void)
{
	while (justify() || p_sign() || p_space() || p_prefix() || padding()\
	|| width() || precision())
		;
}
