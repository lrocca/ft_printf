/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:24:21 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/01 19:01:39 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	validate(char *f)
{
	g_var->printed = 0;
	g_var->width = 0;
	g_var->precision = 0;
	g_var->minus = 0;
	g_var->padding = ' ';
	(void)f;
	return (1);
}

int		ft_printf(const char *f, ...)
{
	t_opt	var;

	if (!f)
		return (0);
	g_var = &var;
	va_start(g_var->args, f);
	while (*f)
	{
		if (*f == '%' && *(f + 1))
		{
			if (validate((char *)(f + 1)) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*f, 1);
			g_var->printed++;
		}
		f++;
	}
	va_end(g_var->args);
	return (g_var->printed);
}
