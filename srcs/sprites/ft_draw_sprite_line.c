/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:03:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:03:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_sprite_line(t_world *world, t_spritedata data, int i,
	int bbox_x[2])
{
	int		bbox_y[2];
	int		j;
	int		color;

	bbox_y[0] = world->scr_height / 2 - data.sprite_size / 2;
	bbox_y[1] = world->scr_height / 2 + data.sprite_size / 2;
	j = (bbox_y[0] < 0) ? 0 : bbox_y[0];
	while (j < (bbox_y[1] >= world->scr_height
		? world->scr_height - 1 : bbox_y[1]))
	{
		color = ft_get_tex_color(world->sprites[data.index].texture,
			((i - bbox_x[0]) * 1.0) / (bbox_x[1] - bbox_x[0]),
			((j - bbox_y[0]) * 1.0) / (bbox_y[1] - bbox_y[0]));
		if (color != 0)
			ft_set_screen_pixel(world->screen, i, j, color);
		j++;
	}
}
