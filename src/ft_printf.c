/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:24:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 18:24:38 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	debug(void)
{
	puts("");
	puts("FLAGS----------------");
	printf("justify:\t%5d\n", g_var->justify);
	printf("padding:\t%5s\n", g_var->padding == ' ' ? "space" : g_var->padding == '0' ? "zero" : "err");
	printf("width:\t\t%5d\n", g_var->width);
	printf("precision:\t%5d\n", g_var->precision);
	puts("---------------------");
	printf("PRINTED\t\t%5d\n", g_var->printed);
}

int		validate(void)
{
	g_var->format++;
	g_var->justify = 0;
	g_var->padding = ' ';
	g_var->width = 0;
	g_var->precision = -1;
	flags();
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
	g_var->printed = 0;
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
	debug();
	return (g_var->printed);
}
