/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:14:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 11:14:45 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstaddback(t_list **list, t_list *elem)
{
	if (*list)
		ft_lstlast(*list)->next = elem;
	else
		*list = elem;
	return (*list);
}
