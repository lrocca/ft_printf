/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:58:32 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/13 17:31:09 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	else
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	return (dst);
}
