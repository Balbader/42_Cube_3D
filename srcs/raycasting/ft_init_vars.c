/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:56:44 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:56:47 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dda	ft_init_vars(t_world *world, double ray[2])
{
	t_dda	vars;

	vars.delta_dist[0] = fabs(1.0 / ray[0]);
	vars.delta_dist[1] = fabs(1.0 / ray[1]);
	vars.map_pos[0] = floor(world->pos[0]);
	vars.map_pos[1] = floor(world->pos[1]);
	vars.step[0] = (ray[0] < 0) ? -1 : 1;
	vars.step[1] = (ray[1] < 0) ? -1 : 1;
	vars.side_dist[0] = (ray[0] < 0)
		? (world->pos[0] - vars.map_pos[0]) * vars.delta_dist[0]
		: (vars.map_pos[0] + 1.0 - world->pos[0]) * vars.delta_dist[0];
	vars.side_dist[1] = (ray[1] < 0)
		? (world->pos[1] - vars.map_pos[1]) * vars.delta_dist[1]
		: (vars.map_pos[1] + 1.0 - world->pos[1]) * vars.delta_dist[1];
	return (vars);
}
