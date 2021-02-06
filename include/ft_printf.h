/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:50:12 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/06 16:52:34 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include "../libft/libft.h"

# define TYPES "diuxXcsp%"
# define FLAGS "0123456789-*."

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16X "0123456789ABCDEF"

int				ft_printf(const char *f, ...);
int				flags(void);
int				types(void);
int				print(void);

typedef	struct	s_opt
{
	int			justify;
	char		padding;
	int			width;
	int			precision;
	int			negative;
	int			ignore;
	int			printed;
	char		type;
	char		*buffer;
	va_list		args;
	const char	*format;
}				t_opt;

t_opt			*g_var;

#endif
