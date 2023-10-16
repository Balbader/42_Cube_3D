/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:56:04 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 06:56:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_mlx *mlx, int *pos)
{
	mlx->player[X_POS] = pos[0] + 0.5f;
	mlx->player[Y_POS] = pos[1] + 0.5f;
	mlx->player[X_PIXEL] = mlx->player[X_POS] * 64;
	mlx->player[Y_PIXEL] = mlx->player[Y_POS] * 64;
	mlx->delta[0] = cos(mlx->player[ANGLE]) * 5;
	mlx->delta[1] = sin(mlx->player[ANGLE]) * 5;
}
