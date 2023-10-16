/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/08 11:32:02 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_camera(t_world *world)
{
	if (world->cam_dir == E || world->cam_dir == W)
	{
		world->dir[0] = 0;
		world->dir[1] = (world->cam_dir == E) ? 1 : -1;
		world->cam_plane[0] = (world->cam_dir == E) ? 0.66 : -0.66;
		world->cam_plane[1] = 0;
	}
	else
	{
		world->dir[0] = (world->cam_dir == S) ? 1 : -1;
		world->dir[1] = 0;
		world->cam_plane[0] = 0;
		world->cam_plane[1] = (world->cam_dir == S) ? -0.66 : 0.66;
	}
}
