/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:52:04 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:52:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_rotate(t_world *world)
{
	double	tmp;
	double	angle;

	if (!world->ctrls.right && !world->ctrls.left)
		return (FALSE);
	angle = (world->ctrls.left) ? M_PI / 100 : -M_PI / 100;
	tmp = world->dir[0];
	world->dir[0] = tmp * cos(angle) - world->dir[1] * sin(angle);
	world->dir[1] = tmp * sin(angle) + world->dir[1] * cos(angle);
	tmp = world->cam_plane[0];
	world->cam_plane[0] = tmp * cos(angle) - world->cam_plane[1] * sin(angle);
	world->cam_plane[1] = tmp * sin(angle) + world->cam_plane[1] * cos(angle);
	return (TRUE);
}
