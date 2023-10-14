/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:34:54 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:34:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_vertical_while(t_mlx *mlx, double rayon[2], \
		double offset, double end_pos[2])
{
	int		map[2];
	int		dof;

	dof = 0;
	map[1] = 0;
	while (map[1] >= 0 && map[1] < mlx->data->map_height
		&& dof < ft_strlen(mlx->data->map[map[1]]))
	{
		map[X] = (int)(rayon[X]) >> 6;
		map[1] = (int)(rayon[1]) >> 6;
		if (map[1] < 0 && map[X] < 0)
			break ;
		if (0 <= map[1] && map[1] < mlx->data->map_height && 0 <= map[X]
			&& map[X] < (int)ft_strlen(mlx->data->map[map[1]])
			&& mlx->data->map[map[1]][map[X]] == '1')
			return (end_pos[X] = rayon[X], end_pos[1] = rayon[1]
				, dist(mlx->player[X_PIXEL], mlx->player[Y_PIXEL]
					, rayon[X], rayon[1]));
		else
		{
			rayon[X] += ((rayon[1] += offset[1], offset[X]));
			dof++;
		}
	}
	return (1000000);
}
