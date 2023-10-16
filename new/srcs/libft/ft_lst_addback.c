/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:58:08 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 15:58:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lst_addback(t_list **lst, t_list *elem)
{
	if (*lst)
		ft_lstlast(*lst)->next = elem;
	else
		*lst = elem;
	return (*lst);
}
