/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textured_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:54:21 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:54:23 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_textured_line(t_world *world, int i, t_texdata data)
{
	int		j;
	int		start;
	int		end;
	t_img	texture;
	int		color;

	start = world->scr_height / 2 - data.line_height / 2;
	end = world->scr_height / 2 + data.line_height / 2;
	texture = world->textures[data.side];
	j = 0;
	while (j < (start < 0 ? 0 : start))
		ft_set_screen_pixel(world->screen, i, j++, world->color_ceiling);
	while (j < (end >= world->scr_height ? world->scr_height - 1 : end))
	{
		color = ft_get_tex_color(texture, data.wall_x,
			((j - start) * 1.0) / (end - start));
		ft_set_screen_pixel(world->screen, i, j++, color);
	}
	while (j < world->scr_height)
		ft_set_screen_pixel(world->screen, i, j++, world->color_floor);
}
