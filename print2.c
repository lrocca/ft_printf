/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:04:33 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/11 12:38:14 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	a_sign(void)
{
	char	*s;

	if (g_var.negative)
	{
		if (!(s = ft_strjoin("-", g_var.buffer)))
			return (-1);
		free(g_var.buffer);
		g_var.buffer = s;
	}
	else if (g_var.sign)
	{
		if (!(s = ft_strjoin("+", g_var.buffer)))
			return (-1);
		free(g_var.buffer);
		g_var.buffer = s;
	}
	return (0);
}

int	a_space(void)
{
	char	*s;

	if (g_var.space && !g_var.negative)
	{
		if (!(s = ft_strjoin(" ", g_var.buffer)))
			return (-1);
		free(g_var.buffer);
		g_var.buffer = s;
	}
	return (0);
}
