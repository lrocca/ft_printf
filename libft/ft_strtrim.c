/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:13:18 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/18 11:06:45 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	char	*end;
	size_t	len;

	if (!set || !s1)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen((char *)s1);
	while (*start && ft_isset(*start, set))
		start++;
	while (start < end && ft_isset(*(end - 1), set))
		end--;
	len = end - start + 1;
	if (!(str = malloc(len)))
		return (NULL);
	ft_strlcpy(str, start, len);
	return (str);
}
