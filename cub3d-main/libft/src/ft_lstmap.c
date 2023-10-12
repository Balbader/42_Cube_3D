/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:12 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:09 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*mapped;

	root = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	mapped = root;
	while (lst)
	{
		mapped->next = ft_lstnew((*f)(lst->content));
		if (!mapped->next)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		mapped = mapped->next;
		lst = lst->next;
	}
	return (root);
}
