/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:27:29 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/03 19:29:26 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	fill(char padding[2], size_t len)
{
	char	*s;

	if (!g_var->padding)
	{
		while ((size_t)g_var->width > len)
		{
			s = ft_strjoin(padding, g_var->buffer);
			free(g_var->buffer);
			g_var->buffer = s;
			len = ft_strlen(g_var->buffer);
		}
	}
	else
	{
		while ((size_t)g_var->width > len)
		{
			s = ft_strjoin(g_var->buffer, padding);
			free(g_var->buffer);
			g_var->buffer = s;
			len = ft_strlen(g_var->buffer);
		}
	}
}

static void	precision(void)
{
	char	*s;
	size_t	len;

	if (g_var->precision < 0 || g_var->type == 'c' || g_var->type == 'p')
		return ;
	if (g_var->type == 's')
		g_var->buffer[g_var->precision] = '\0';
	else if (g_var->precision == 0 && g_var->buffer[0] == '0')
	{
		g_var->buffer[0] = '\0';
		return ;
	}
	else if ((len = ft_strlen(g_var->buffer)) && len < (size_t)g_var->precision)
	{
		while ((size_t)g_var->precision > len)
		{
			s = ft_strjoin("0", g_var->buffer);
			free(g_var->buffer);
			g_var->buffer = s;
			len = ft_strlen(g_var->buffer);
		}
	}
}

static void	width(void)
{
	char	padding[2];
	size_t	len;

	padding[0] = g_var->precision >= 0 ? ' ' : g_var->padding;
	padding[1] = '\0';
	len = ft_strlen(g_var->buffer);
	if (len < (size_t)g_var->width)
		fill(padding, len);
}

int			print(void)
{
	precision();
	width();
	g_var->printed += ft_strlen(g_var->buffer);
	ft_putstr_fd(g_var->buffer, 1);
	return (0);
}

int			print_null(void)
{
	if (!(g_var->buffer = ft_strdup("(null)")))
		return (-1);
	return (print());
}
