/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:59:17 by lrocca            #+#    #+#             */
/*   Updated: 2021/01/15 23:07:01 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (lst && *lst)
	{
		curr = *lst;
		*lst = NULL;
		while (curr)
		{
			next = curr->next;
			ft_lstdelone(curr, del);
			curr = next;
		}
	}
}
