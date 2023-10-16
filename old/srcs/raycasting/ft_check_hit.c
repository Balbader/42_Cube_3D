/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:58:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:58:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_check_hit(t_world *world, t_dda *vars, t_texdata *data, double ray[2])
{
	if (vars->side_dist[0] < vars->side_dist[1])
	{
		vars->side_dist[0] += vars->delta_dist[0];
		vars->map_pos[0] += vars->step[0];
		data->side = ray[0] > 0 ? N : S;
	}
	else
	{
		vars->side_dist[1] += vars->delta_dist[1];
		vars->map_pos[1] += vars->step[1];
		data->side = ray[1] > 0 ? E : W;
	}
	return (world->map[vars->map_pos[0]][vars->map_pos[1]] == 1);
}
