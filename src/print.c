/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:27:29 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 18:19:03 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print(void)
{
	g_var->printed += ft_strlen(g_var->buffer);
	ft_putstr_fd(g_var->buffer, 1);
	return (0);
}

int	print_null(void)
{
	if (!(g_var->buffer = ft_strdup("(null)")))
		return (-1);
	return (print());
}
