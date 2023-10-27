/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:30:59 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:31:01 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * M_PI : Pi macro
 * tan : <math.h> function : returns the tangent of a number (angle in radians).
 *
 * 1. Define the radiand value of ra : atan
 * 2. check if ra < Pi || ra > Pi 
*/

#define X 0

double	ft_horizontal_check(t_mlx *mlx, double ra, double end_pos[2])
{
	double	ray[2];
	double	offset[2];
	float	atan;

	atan = -1 / tan(ra);
	if (ra < M_PI)
	{
		ray[1] = (((int)mlx->player[Y_PIXEL] >> 6) << 6) - 0.0002;
		ray[X] = (mlx->player[Y_PIXEL] - ray[1]) * atan + mlx->player[X_PIXEL];
		offset[1] = -64;
		offset[X] = -offset[1] * atan;
	}
	if (ra > M_PI)
	{
		ray[1] = (((int)mlx->player[Y_PIXEL] >> 6) << 6) + 64;
		ray[X] = (mlx->player[Y_PIXEL] - ray[1]) * atan + mlx->player[X_PIXEL];
		offset[1] = 64;
		offset[X] = -offset[1] * atan;
	}
	if (ra == 0 || ra == M_PI)
		return (1000000);
	return (ft_horizontal_while(mlx, ray, offset, end_pos));
}
