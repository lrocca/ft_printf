/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:51:30 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/03 15:57:22 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	int				sign;
	unsigned int	nb;

	sign = 0;
	len = ft_numlen((unsigned int)n, 10);
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		sign = 1;
		len = ft_numlen(nb, 10) + 1;
	}
	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	if (sign)
		str[0] = '-';
	str[--len] = '0' + (nb % 10);
	while (nb /= 10)
		str[--len] = '0' + (nb % 10);
	return (str);
}
