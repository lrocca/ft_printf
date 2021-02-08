/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:50:25 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/18 12:51:35 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (d[i] && i < size)
		i++;
	while (i + 1 < size && *s)
		d[i++] = *s++;
	if (i < size)
		d[i] = '\0';
	while (*s++)
		i++;
	return (i);
}
