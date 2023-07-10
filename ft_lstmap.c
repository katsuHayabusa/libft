/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:55:59 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/14 18:56:11 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&new_list, *del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst -> next;
	}
	return (new_list);
}
