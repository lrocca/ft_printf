/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:40:07 by lrocca            #+#    #+#             */
/*   Updated: 2021/02/06 16:30:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(unsigned long long n, int base)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
