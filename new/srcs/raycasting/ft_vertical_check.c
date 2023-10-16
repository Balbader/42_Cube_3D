/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:33:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:33:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define X 0

double	ft_vertical_check(t_mlx *mlx, double ra, double end_pos[2])
{
	double	rayon[2];
	double	offset[2];
	double	ntan;

	ntan = -tan(ra);
	if ((M_PI / 2) < ra && ra < (3 * M_PI / 2))
	{
		rayon[X] = (((int)mlx->player[X_PIXEL] >> 6) << 6) + 64;
		rayon[1] = (mlx->player[X_PIXEL] - rayon[X]) * ntan;
		rayon[1] += mlx->player[Y_PIXEL];
		offset[X] = 64;
		offset[1] = -offset[X] * ntan;
	}
	if (ra < (M_PI / 2) || (3 * M_PI / 2) < ra)
	{
		rayon[X] = (((int)mlx->player[X_PIXEL] >> 6) << 6) - 0.0002;
		rayon[1] = (mlx->player[X_PIXEL] - rayon[X]) * ntan;
		rayon[1] += mlx->player[Y_PIXEL];
		offset[X] = -64;
		offset[1] = -offset[X] * ntan;
	}
	if (ra == (M_PI / 2) || ra == (3 * M_PI / 2))
		return (1000000);
	return (ft_vertical_while(mlx, rayon, offset, end_pos));
}
