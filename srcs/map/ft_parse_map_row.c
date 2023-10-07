/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_row.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:19:56 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:19:58 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_map_row(t_world *world, int i)
{
	int		j;

	j = 0;
	while (world->raw_map[j] && world->raw_map[j] != '\n')
		j++;
	world->char_map[i] = ft_substr(world->raw_map, 0, j);
	world->raw_map += j + 1;
	j = 0;
	while (world->char_map[i][j])
	{
		if (ft_indexof(" \t012NWSE", world->char_map[i][j]) < 0)
			ft_check_parsing(world, "Map contains invalid characters", 0);
		j++;
	}
	if (ft_strlen(world->char_map[i]) > world->map_width)
		world->map_width = ft_strlen(world->char_map[i]);
}
