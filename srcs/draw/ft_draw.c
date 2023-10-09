/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:34:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:34:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_world *world)
{
	ft_draw_walls(world);
	ft_draw_sprites(world);
	if (world->save)
	{
		ft_flip_pix(world);
		write(world->fd_save, world->screen.data, world->nb_pixels);
		close(world->fd_save);
	}
	else
	{
		mlx_put_image_to_window(world->mlx.ptr, world->mlx.win,
			world->screen.ptr, 0, 0);
	}
}
