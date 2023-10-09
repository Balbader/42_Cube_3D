/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:51:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:51:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_move(t_world *world)
{
	double	dx;
	double	dy;
	double	speed;

	speed = 0.15;
	if (!(world->ctrls.w || world->ctrls.s || world->ctrls.a || world->ctrls.d))
		return (FALSE);
	if (world->ctrls.w || world->ctrls.s)
	{
		dx = world->dir[0] * (world->ctrls.w ? speed : -speed);
		dy = world->dir[1] * (world->ctrls.w ? speed : -speed);
	}
	else
	{
		dx = world->cam_plane[0] * (world->ctrls.d ? speed : -speed);
		dy = world->cam_plane[1] * (world->ctrls.d ? speed : -speed);
	}
	if (world->map[(int)(world->pos[0] + dx)][(int)(world->pos[1] + dy)] != 1)
	{
		world->pos[0] += dx;
		world->pos[1] += dy;
	}
	return (TRUE);
}
