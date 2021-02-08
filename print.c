/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:27:29 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/08 15:34:04 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill(char padding[2], size_t len)
{
	char	*s;

	if (padding[0] == ' ')
		g_var->negative = 0;
	if (!g_var->justify)
	{
		while ((size_t)g_var->width > len + g_var->negative)
		{
			if (!(s = ft_strjoin(padding, g_var->buffer)))
				return (-1);
			free(g_var->buffer);
			g_var->buffer = s;
			len = ft_strlen(g_var->buffer);
		}
	}
	else
		while ((size_t)g_var->width > len + g_var->negative)
		{
			if (!(s = ft_strjoin(g_var->buffer, padding)))
				return (-1);
			free(g_var->buffer);
			g_var->buffer = s;
			len = ft_strlen(g_var->buffer);
		}
	return (0);
}

static int	precision(void)
{
	char	*s;
	size_t	len;

	if (g_var->precision < 0 || g_var->type == 'c')
		return (0);
	if (g_var->type == 'p' && g_var->buffer[0] == '0' && g_var->precision == 0)
		g_var->buffer[0] = '\0';
	else if (g_var->type == 's')
		g_var->buffer[g_var->precision] = '\0';
	else if (!g_var->precision && g_var->buffer[0] == '0')
		g_var->buffer[0] = '\0';
	else if ((len = ft_strlen(g_var->buffer)) && len < (size_t)g_var->precision)
	{
		while ((size_t)g_var->precision > len)
		{
			if (!(s = ft_strjoin("0", g_var->buffer)))
				return (-1);
			free(g_var->buffer);
			g_var->buffer = s;
			len = ft_strlen(g_var->buffer);
		}
	}
	return (0);
}

static int	width(void)
{
	char	*s;
	char	padding[2];
	size_t	len;

	padding[0] = g_var->precision >= 0 || g_var->justify ? ' ' : g_var->padding;
	padding[1] = '\0';
	if (g_var->negative && padding[0] == ' ')
	{
		if (!(s = ft_strjoin("-", g_var->buffer)))
			return (-1);
		free(g_var->buffer);
		g_var->buffer = s;
	}
	len = ft_strlen(g_var->buffer);
	if (len < (size_t)g_var->width)
		fill(padding, len);
	if (g_var->negative && padding[0] == '0')
	{
		if (!(s = ft_strjoin("-", g_var->buffer)))
			return (-1);
		free(g_var->buffer);
		g_var->buffer = s;
	}
	return (0);
}

int			print(void)
{
	char	*s;

	if (precision() == -1)
		return (-1);
	if (g_var->type == 'p')
	{
		if (!(s = ft_strjoin("0x", g_var->buffer)))
			return (-1);
		free(g_var->buffer);
		g_var->buffer = s;
	}
	if (width() == -1)
		return (-1);
	g_var->printed += ft_strlen(g_var->buffer);
	while (*g_var->buffer)
	{
		if (*g_var->buffer == 'c' && g_var->null)
			ft_putchar_fd('\0', 1);
		else
			ft_putchar_fd(*g_var->buffer, 1);
		g_var->buffer++;
	}
	return (0);
}
