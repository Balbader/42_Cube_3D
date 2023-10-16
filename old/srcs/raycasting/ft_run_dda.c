/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:59:58 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:00:03 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_run_dda(t_world *world, int i, double ray[2])
{
	t_dda		vars;
	t_bool		hit;
	t_texdata	data;

	vars = ft_init_vars(world, ray);
	hit = FALSE;
	while (!hit)
		hit = ft_check_hit(world, &vars, &data, ray);
	data.wall_dist = (data.side == N || data.side == S)
		? (vars.map_pos[0] - world->pos[0] + (1 - vars.step[0]) / 2) / ray[0]
		: (vars.map_pos[1] - world->pos[1] + (1 - vars.step[1]) / 2) / ray[1];
	world->depth_buffer[i] = data.wall_dist;
	data.wall_x = (data.side == N || data.side == S)
		? world->pos[1] + data.wall_dist * ray[1]
		: world->pos[0] + data.wall_dist * ray[0];
	data.wall_x -= floor(data.wall_x);
	data.line_height = (data.wall_dist > 0)
		? world->scr_height / data.wall_dist
		: 2147483647;
	ft_draw_textured_line(world, i, data);
}
