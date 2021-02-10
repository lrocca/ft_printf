/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:50:12 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/10 17:17:12 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16X "0123456789ABCDEF"

int				ft_printf(const char *f, ...);

void			flags(void);

int				types(void);
int				type_d(void);
int				type_u(void);
int				type_x(void);
int				type_xx(void);
int				type_c(void);
int				type_s(void);
int				type_p(void);
int				type_percent(void);

int				print(void);

typedef	struct	s_opt
{
	int			justify;
	char		padding;
	int			width;
	int			precision;
	int			null;
	int			negative;
	int			sign;
	int			space;
	int			prefix;
	int			printed;
	char		type;
	char		*buffer;
	va_list		args;
	const char	*format;
}				t_opt;

extern t_opt	g_var;

#endif
