/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:22:30 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 16:56:21 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	width(void)
{
	if (*g_var->format == '*')
	{
		g_var->width = va_arg(g_var->args, int);
		if (g_var->width < 0)
		{
			g_var->justify = 1;
			g_var->width *= -1;
		}
		g_var->format++;
	}
	else if (ft_isdigit(*g_var->format))
	{
		g_var->width = ft_atoi(g_var->format);
		while (ft_isdigit(*g_var->format))
			g_var->format++;
	}
}

static void	precision(void)
{
	g_var->format++;
	g_var->precision = 0;
	if (*g_var->format == '*')
	{
		g_var->precision = va_arg(g_var->args, int);
		g_var->format++;
	}
	else if (ft_isdigit(*g_var->format))
	{
		g_var->precision = ft_atoi(g_var->format);
		while (ft_isdigit(*g_var->format))
			g_var->format++;
	}
}

int			flags(void)
{
	if (*g_var->format == '-')
	{
		g_var->justify = 1;
		g_var->format++;
	}
	if (*g_var->format == '0')
	{
		g_var->padding = '0';
		g_var->format++;
	}
	width();
	if (*g_var->format == '.')
		precision();
	return (0);
}
