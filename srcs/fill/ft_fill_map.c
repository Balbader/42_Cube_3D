/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:29:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:29:51 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_map(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (i < (*data)->map_height && tmp)
	{
		(*data)->map[i] = ft_copy_str((*data)->map[i], tmp->line);
		tmp = tmp->next;
		i++;
	}
}
