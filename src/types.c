/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:53:53 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/06 15:27:06 by lrocca           ###   ########.fr       */
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
		if (!g_var->ignore)
		{
			s = ft_strdup(g_var->buffer + 1);
			free(g_var->buffer);
			g_var->buffer = s;
		}
	}
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

int	types_fwd(void)
{
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
