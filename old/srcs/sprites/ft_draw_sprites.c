/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:06:47 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:06:50 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_sprites(t_world *world)
{
	t_spritedata	data;
	double			sprite_pos[2];
	double			det;

	ft_compute_distances(world);
	ft_sort_sprites(world);
	data.index = 0;
	while (data.index < world->nb_sprites)
	{
		sprite_pos[0] = world->sprites[data.index].pos[0] + 0.5 - world->pos[0];
		sprite_pos[1] = world->sprites[data.index].pos[1] + 0.5 - world->pos[1];
		det = 1.0 / (world->cam_plane[0] * world->dir[1]
			- world->dir[0] * world->cam_plane[1]);
		data.transform[0] = det * (world->dir[1] * sprite_pos[0]
			- world->dir[0] * sprite_pos[1]);
		data.transform[1] = det * (-world->cam_plane[1] * sprite_pos[0]
			+ world->cam_plane[0] * sprite_pos[1]);
		data.sprite_x = (int)((world->scr_width / 2) *
			(1 + data.transform[0] / data.transform[1]));
		data.sprite_size = abs((int)(world->scr_height / data.transform[1]));
		ft_draw_sprite(world, data);
		data.index++;
	}
}
