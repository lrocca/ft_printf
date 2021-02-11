/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:45:27 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/11 12:35:38 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_sign(void)
{
	if (*g_var.format == '+')
	{
		g_var.sign = 1;
		g_var.format++;
		return (1);
	}
	return (0);
}

int	p_space(void)
{
	if (*g_var.format == ' ')
	{
		g_var.space = 1;
		g_var.format++;
		return (1);
	}
	return (0);
}

int	p_prefix(void)
{
	if (*g_var.format == '#')
	{
		g_var.prefix = 1;
		g_var.format++;
		return (1);
	}
	return (0);
}
