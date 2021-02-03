/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:24:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/03 16:38:27 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/types.h"

void	debug(void)
{
	puts("");
	puts("FLAGS----------------");
	printf("justify:\t%5d\n", g_var->justify);
	printf("padding:\t%5s\n", g_var->padding == ' ' ? "space" : g_var->padding == '0' ? "zero" : "err");
	printf("width:\t\t%5d\n", g_var->width);
	printf("precision:\t%5d\n", g_var->precision);
	printf("type:\t\t%5c\n", g_var->type);
	puts("---------------------");
	printf("PRINTED\t\t%5d\n", g_var->printed);
}

int		types(void)
{
	g_var->type = *g_var->format;
	if ((g_var->type == 'd' || g_var->type == 'i') && type_d() != -1)
		return (0);
	else if (g_var->type == 'u' && type_u() != -1)
		return (0);
	else if (g_var->type == 'x' && type_x() != -1)
		return (0);
	else if (g_var->type == 'X' && type_xx() != -1)
		return (0);
	else if (g_var->type == 'c' && type_c() != -1)
		return (0);
	else if (g_var->type == 's' && type_s() != -1)
		return (0);
	else if (g_var->type == 'p' && type_p() != -1)
		return (0);
	else if (g_var->type == '%' && type_percent() != -1)
		return (0);
	return (-1);
}

int		format(void)
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
			if (format() == -1)
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
