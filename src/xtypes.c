/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtypes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:36:43 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/03 16:31:33 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/types.h"

int	type_u(void)
{
	if (!(g_var->buffer = ft_utoa_base(va_arg(g_var->args, size_t), BASE10)))
		return (-1);
	return (print());
}

int	type_x(void)
{
	if (!(g_var->buffer = ft_utoa_base(va_arg(g_var->args, size_t), BASE16)))
		return (-1);
	return (print());
}

int	type_xx(void)
{
	if (!(g_var->buffer = ft_utoa_base(va_arg(g_var->args, size_t), BASE16X)))
		return (-1);
	return (print());
}

int	type_p(void)
{
	char *s;

	if (!(s = ft_utoa_base(va_arg(g_var->args, size_t), BASE16)))
		return (-1);
	if (!(g_var->buffer = ft_strjoin("0x", s)))
		return (-1);
	free(s);
	return (print());
}
