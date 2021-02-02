/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:53:53 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 13:07:24 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	type_d(void)
{
	int	n;

	n = va_arg(g_var->args, int);
	ft_putnbr_fd(n, 1);
	return (0);
}

int	type_c(void)
{
	int	c;

	c = va_arg(g_var->args, int);
	ft_putchar_fd(c, 1);
	g_var->printed++;
	return (0);
}

int	type_s(void)
{
	char	*s;

	s = va_arg(g_var->args, char*);
	ft_putstr_fd(s, 1);
	g_var->printed += ft_strlen(s);
	return (0);
}

int	type_p(void)
{
	char	*s;

	s = va_arg(g_var->args, char*);
	ft_putstr_fd(s, 1);
	return (0);
}

int	type_percent(void)
{
	ft_putchar_fd('%', 1);
	return (0);
}

int	types(void)
{
	if ((*g_var->format == 'd' || *g_var->format == 'i') && type_d() != -1)
		return (0);
	else if (*g_var->format == 'c' && type_c() != -1)
		return (0);
	else if (*g_var->format == 's' && type_s() != -1)
		return (0);
	else if (*g_var->format == 'p' && type_p() != -1)
		return (0);
	else if (*g_var->format == '%' && type_percent() != -1)
		return (0);
	return (-1);
}
