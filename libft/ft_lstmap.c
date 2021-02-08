/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:10:53 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/15 23:45:20 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*el;

	new = NULL;
	while (lst)
	{
		if (!(el = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, el);
		lst = lst->next;
	}
	return (new);
}
