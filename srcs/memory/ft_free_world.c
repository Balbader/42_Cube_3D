/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:38:29 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:38:30 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_world(t_world *world)
{
	int		i;

	if (world->map)
	{
		i = 0;
		while (i < world->map_height)
			free(world->map[i++]);
		free(world->map);
	}
	if (world->sprites)
		free(world->sprites);
	if (world->depth_buffer)
		free(world->depth_buffer);
	if (world->screen.data)
		mlx_destroy_image(world->mlx.ptr, world->screen.ptr);
	ft_free_textures(world);
	if (world->mlx.win)
		mlx_destroy_window(world->mlx.ptr, world->mlx.win);
	free(world);
}
