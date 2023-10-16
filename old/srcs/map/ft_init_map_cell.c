/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_cell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:16:30 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:16:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map_cell(t_world *world, int i, int j, t_bool *parsed_camera)
{
	if (j >= ft_strlen(world->char_map[i]) || world->char_map[i][j] <= ' ')
		world->map[i][j] = -1;
	else if (ft_indexof("012", world->char_map[i][j]) >= 0)
		world->map[i][j] = world->char_map[i][j] - '0';
	else if (ft_indexof("NWSE", world->char_map[i][j]) >= 0)
	{
		if (*parsed_camera)
			ft_check_parsing(world, "Map must only contain one player", 0);
		else
		{
			world->cam_dir = ft_indexof("NWSE", world->char_map[i][j]);
			world->map[i][j] = 0;
			world->pos[0] = i;
			world->pos[1] = j;
			*parsed_camera = TRUE;
		}
	}
	if (world->map[i][j] == 2)
		world->nb_sprites++;
}
