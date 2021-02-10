/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:36:43 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/10 19:17:11 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_u(void)
{
	if (!(g_var.buffer = ft_utoa_base(va_arg(g_var.args, unsigned int),\
	BASE10)))
		return (-1);
	return (print());
}

int	type_x(void)
{
	if (!(g_var.buffer = ft_utoa_base(va_arg(g_var.args, unsigned int),\
	BASE16)))
		return (-1);
	if (g_var.buffer[0] == '0')
		g_var.prefix = 0;
	return (print());
}

int	type_xx(void)
{
	if (!(g_var.buffer = ft_utoa_base(va_arg(g_var.args, unsigned int),\
	BASE16X)))
		return (-1);
	if (g_var.buffer[0] == '0')
		g_var.prefix = 0;
	return (print());
}

int	type_p(void)
{
	if (!(g_var.buffer = ft_utoa_base(va_arg(g_var.args, size_t),\
	BASE16)))
		return (-1);
	return (print());
}
