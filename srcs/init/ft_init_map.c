/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:00:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/30 13:00:46 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	(*data)->map = (char **)malloc(sizeof(char *) * ((*data)->map_height + 1));
	if (!(*data)->map)
		ft_clear_all_exit(data, list, MAPFAIL);
	while (i < (*data)->map_height)
	{
		(*data)->map[i] = (char *)malloc(sizeof(char) * \
			((*data)->map_width + 1));
		if (!(*data)->map[i])
		{
			ft_free_array((*data)->map);
			ft_clear_all_exit(data, list, MAPFAIL);
		}
		(*data)->map[i] = ft_memset((*data)->map[i], ' ', (*data)->map_width);
		(*data)->map[i][(*data)->map_width] = '\0';
		i++;
	}
	(*data)->map[i] = NULL;
}
