/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:24:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 12:51:35 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		validate(void)
{
	g_var->format++;
	g_var->printed = 0;
	g_var->width = 0;
	g_var->precision = 0;
	g_var->minus = 0;
	g_var->padding = ' ';
	if (types() == -1)
		return (-1);
	return (1);
}

int		ft_printf(const char *f, ...)
{
	t_opt	var;

	if (!f)
		return (0);
	g_var = &var;
	g_var->format = f;
	va_start(g_var->args, f);
	while (*g_var->format)
	{
		if (*g_var->format == '%' && *(g_var->format + 1))
		{
			if (validate() == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*g_var->format, 1);
			g_var->printed++;
		}
		g_var->format++;
	}
	va_end(g_var->args);
	return (g_var->printed);
}
