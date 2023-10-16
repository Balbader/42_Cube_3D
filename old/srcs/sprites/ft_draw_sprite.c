/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:05:12 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:05:14 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_sprite(t_world *world, t_spritedata data)
{
	int		bbox_x[2];
	int		i;

	bbox_x[0] = data.sprite_x - data.sprite_size / 2;
	bbox_x[1] = data.sprite_x + data.sprite_size / 2;
	i = (bbox_x[0] < 0) ? 0 : bbox_x[0];
	while (i <= (bbox_x[1] >= world->scr_width ?
		world->scr_width - 1 : bbox_x[1]))
	{
		if (data.transform[1] > 0 && data.transform[1] < world->depth_buffer[i])
			ft_draw_sprite_line(world, data, i, bbox_x);
		i++;
	}
}
