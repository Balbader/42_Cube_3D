/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:18:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:18:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_world *world)
{
	int		i;
	int		j;
	t_bool	cam_parsed;

	cam_parsed = FALSE;
	world->nb_sprites = 0;
	world->map = ft_calloc(world->map_height, sizeof(int *));
	i = 0;
	while (i < world->map_height)
	{
		world->map[i] = ft_calloc(world->map_width, sizeof(int));
		j = 0;
		while (j < world->map_width)
			ft_init_map_cell(world, i, j++, &cam_parsed);
		free(world->char_map[i]);
		i++;
	}
	if (!cam_parsed)
		ft_check_parsing(world, "Player position is not defined", 0);
	free(world->char_map);
}
