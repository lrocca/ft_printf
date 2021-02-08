/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:45:44 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/15 20:50:40 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i + j] && (i + j) < n)
	{
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		if (s1[i + j] != s2[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if ((!s1[i + j] && !s2[j]) || ((i + j) == n && !s2[j]))
		return ((char *)s1 + i);
	return (NULL);
}
