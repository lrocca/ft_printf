/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:27:29 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/10 19:28:53 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	fill(char padding[2])
{
	int		offset;
	char	*s;

	offset = padding[0] == ' ' ? 0 : g_var.sign || g_var.space;
	offset = padding[0] == '0' && g_var.prefix ? 2 : offset;
	if (!g_var.justify)
	{
		while ((size_t)g_var.width > ft_strlen(g_var.buffer) + offset)
		{
			if (!(s = ft_strjoin(padding, g_var.buffer)))
				return (-1);
			free(g_var.buffer);
			g_var.buffer = s;
		}
	}
	else
		while ((size_t)g_var.width > ft_strlen(g_var.buffer) + offset)
		{
			if (!(s = ft_strjoin(g_var.buffer, padding)))
				return (-1);
			free(g_var.buffer);
			g_var.buffer = s;
		}
	return (0);
}

static int	precision(void)
{
	char	*s;
	size_t	len;

	if (g_var.precision < 0 || g_var.type == 'c')
		return (0);
	if (g_var.type == 'p' && g_var.buffer[0] == '0' && g_var.precision == 0)
		g_var.buffer[0] = '\0';
	else if (g_var.type == 's')
		g_var.buffer[g_var.precision] = '\0';
	else if (!g_var.precision && g_var.buffer[0] == '0')
		g_var.buffer[0] = '\0';
	else if ((len = ft_strlen(g_var.buffer)) && len < (size_t)g_var.precision)
	{
		while ((size_t)g_var.precision > len)
		{
			if (!(s = ft_strjoin("0", g_var.buffer)))
				return (-1);
			free(g_var.buffer);
			g_var.buffer = s;
			len = ft_strlen(g_var.buffer);
		}
	}
	return (0);
}

static int	prefix(void)
{
	char	*s;

	if (g_var.type == 'p' || (g_var.type == 'x' && g_var.prefix))
	{
		if (!(s = ft_strjoin("0x", g_var.buffer)))
			return (-1);
		free(g_var.buffer);
		g_var.buffer = s;
	}
	else if (g_var.type == 'X' && g_var.prefix)
	{
		if (!(s = ft_strjoin("0X", g_var.buffer)))
			return (-1);
		free(g_var.buffer);
		g_var.buffer = s;
	}
	return (0);
}

static int	width(void)
{
	char	padding[2];

	padding[0] = g_var.precision >= 0 || g_var.justify ? ' ' : g_var.padding;
	padding[1] = '\0';
	if (padding[0] == ' ')
	{
		if (prefix() == -1)
			return (-1);
		if (a_space() == -1)
			return (-1);
		if (a_sign() == -1)
			return (-1);
	}
	if (ft_strlen(g_var.buffer) < (size_t)g_var.width)
		fill(padding);
	if (padding[0] == '0')
	{
		if (prefix() == -1)
			return (-1);
		if (a_space() == -1)
			return (-1);
		if (a_sign() == -1)
			return (-1);
	}
	return (0);
}

int			print(void)
{
	if (g_var.negative)
		g_var.sign = 1;
	if (g_var.sign)
		g_var.space = 0;
	if (precision() == -1)
		return (-1);
	if (width() == -1)
		return (-1);
	g_var.printed += ft_strlen(g_var.buffer);
	while (*g_var.buffer)
	{
		if (*g_var.buffer == 'c' && g_var.null)
			ft_putchar_fd('\0', 1);
		else
			ft_putchar_fd(*g_var.buffer, 1);
		g_var.buffer++;
	}
	return (0);
}
