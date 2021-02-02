/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:50:12 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/02 18:31:09 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include "../libft/libft.h"

int				ft_printf(const char *f, ...);
int				flags(void);
int				types(void);
int				print(void);
int				print_null(void);

typedef	struct	s_opt
{
	int			justify;
	char		padding;
	int			width;
	int			precision;
	int			printed;
	char		*buffer;
	va_list		args;
	const char	*format;
}				t_opt;

t_opt			*g_var;

#endif
