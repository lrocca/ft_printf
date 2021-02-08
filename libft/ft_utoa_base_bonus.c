/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:32:36 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/03 16:06:24 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned long long n, char *radix)
{
	char	*s;
	size_t	len;
	int		base;

	len = ft_numlen(n, ft_strlen(radix));
	base = ft_strlen(radix);
	if (!(s = malloc(len + 1)))
		return (NULL);
	s[len] = '\0';
	s[--len] = radix[n % base];
	while (n /= base)
		s[--len] = radix[n % base];
	return (s);
}
