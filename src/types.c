/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:53:53 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/06 17:54:39 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/types.h"

int	type_d(void)
{
	int		n;
	char	*s;

	n = va_arg(g_var->args, int);
	if (!(g_var->buffer = ft_strdup(ft_itoa(n))))
		return (-1);
	if (n < 0)
	{
		g_var->negative = 1;
		s = ft_strdup(g_var->buffer + 1);
		free(g_var->buffer);
		g_var->buffer = s;
	}
	return (print());
}

int	type_c(void)
{
	char	c;

	c = va_arg(g_var->args, int);
	if (!c)
		g_var->null = 1;
	if (!(g_var->buffer = malloc(2)))
		return (-1);
	g_var->buffer[0] = c ? c : 'c';
	g_var->buffer[1] = '\0';
	return (print());
}

int	type_s(void)
{
	char	*s;

	if (!(s = va_arg(g_var->args, char*)))
	{
		if (!(g_var->buffer = ft_strdup("(null)")))
			return (-1);
	}
	else if (!(g_var->buffer = ft_strdup(s)))
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
