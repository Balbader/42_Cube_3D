/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:33:40 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:33:41 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_map_size(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		height;
	int		width;

	tmp = *list;
	height = 0;
	width = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (tmp)
	{
		height++;
		if (width < ft_strlen(tmp->line))
			width = ft_strlen(tmp->line);
		tmp = tmp->next;
	}
	(*data)->map_height = height;
	(*data)->map_width = width;
}
}
