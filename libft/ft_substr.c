/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:22:59 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/15 21:04:53 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || !len || (unsigned int)ft_strlen((char *)s) <= start)
		return (ft_strdup(""));
	if (!(sub = malloc(len + 1)))
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
