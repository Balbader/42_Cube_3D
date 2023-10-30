/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_while.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:12 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:32:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define X 0

double	ft_horizontal_while(t_mlx *mlx, double ray[2], double offset[2], \
		double end_pos[2])
{
	int		map[2];
	int		dof;

	dof = 0;
	while (dof < mlx->data->map_height)
	{
		map[X] = (int)(ray[X]) >> 6;
		map[1] = (int)(ray[1]) >> 6;
		if (0 <= map[1] && map[1] < mlx->data->map_height && 0 <= map[X]
			&& map[X] < (int)ft_strlen(mlx->data->map[map[1]])
			&& mlx->data->map[map[1]][map[X]] == '1')
			return (end_pos[X] = ray[X], end_pos[1] = ray[1]
				, ft_dist(mlx->player[X_PIXEL], mlx->player[Y_PIXEL],
					ray[X], ray[1]));
		else
		{
			ray[X] += offset[X];
			ray[1] += offset[1];
			dof++;
		}
	}
	return (1000000);
}
