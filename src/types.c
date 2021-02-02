/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:53:53 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 18:47:32 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/types.h"

int	type_d(void)
{
	int	n;

	n = va_arg(g_var->args, int);
	if (!(g_var->buffer = ft_strdup(ft_itoa(n))))
		return (-1);
	return (print());
}

int	type_c(void)
{
	char	c;

	c = va_arg(g_var->args, int);
	if (!(g_var->buffer = malloc(2)))
		return (-1);
	g_var->buffer[0] = c;
	g_var->buffer[1] = '\0';
	return (print());
}

int	type_s(void)
{
	char	*s;

	if (!(s = va_arg(g_var->args, char*)))
		return (print_null());
	if (!(g_var->buffer = ft_strdup(s)))
		return (-1);
	return (print());
}

int	type_percent(void)
{
	if (!(g_var->buffer = malloc(2)))
		return (-1);
	g_var->buffer[0] = '%';
	g_var->buffer[1] = '\0';
	return (print());
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
