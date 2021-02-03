/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:53:53 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/03 16:36:29 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
