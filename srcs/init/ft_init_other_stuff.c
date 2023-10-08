/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_other_stuff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:55:44 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/08 11:55:45 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_init_other_stuff(t_world *world)
{
	if (!parse_map(world))
		return (FALSE);
	cam_init(world);
	if (!(world->mlx.ptr = mlx_init()))
		return (FALSE);
	load_textures(world);
	if (!sprites_init(world))
		return (FALSE);
	if (!(world->depth_buffer = ft_calloc(world->scr_width, sizeof(double))))
		return (FALSE);
	if (!screen_init(world))
		return (FALSE);
	world->nb_pixels = world->scr_width * world->scr_height *
		(world->screen.bpp >> 3);
	if (world->save)
	{
		world->fd_save = open("cub3d.bmp", O_WRONLY | O_CREAT, 0777);
		write_bmp_header(world);
	}
	else if (!(world->mlx.win = mlx_new_window(world->mlx.ptr, world->scr_width,
		world->scr_height, "Cub3D")))
		return (FALSE);
	return (TRUE);
}
