/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:24:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/06 15:17:34 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/types.h"

static int	istype(char c)
{
	int i;

	i = 0;
	while (TYPES[i])
	{
		if (c == TYPES[i])
			return (1);
		i++;
	}
	return (0);
}

static int	isflag(char c)
{
	int i;

	i = 0;
	while (FLAGS[i])
	{
		if (c == FLAGS[i])
			return (1);
		i++;
	}
	return (0);
}

int			types(void)
{
	while (*g_var->format)
	{
		if (istype(*g_var->format))
		{
			g_var->type = *g_var->format;
			return (types_fwd());
		}
		else if (isflag(*g_var->format))
		{
			g_var->ignore++;
			g_var->format++;
			continue ;
		}
		break ;
	}
	return (0);
}

int			format(void)
{
	g_var->format++;
	g_var->justify = 0;
	g_var->padding = ' ';
	g_var->width = 0;
	g_var->precision = -1;
	g_var->negative = 0;
	g_var->ignore = 0;
	flags();
	if (types() == -1)
		return (-1);
	return (1);
}

int			ft_printf(const char *f, ...)
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
	return (g_var->printed);
}
