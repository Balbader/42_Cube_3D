/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:33:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:33:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_walls(t_world *world)
{
	int		i;
	double	camera_x;
	double	ray[2];

	i = 0;
	while (i < world->scr_width)
	{
		camera_x = 2.0 * i / world->scr_width - 1;
		ray[0] = world->dir[0] + world->cam_plane[0] * camera_x;
		ray[1] = world->dir[1] + world->cam_plane[1] * camera_x;
		ft_run_dda(world, i++, ray);
	}
}
