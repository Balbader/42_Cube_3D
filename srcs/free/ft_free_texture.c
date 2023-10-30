/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:02:19 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/30 13:02:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_texture(t_mlx *mlx)
{
	if (mlx->pict[IMAGE].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[IMAGE].img);
	if (mlx->pict[WALL_NORTH].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_NORTH].img);
	if (mlx->pict[WALL_SOUTH].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_SOUTH].img);
	if (mlx->pict[WALL_WEST].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_WEST].img);
	if (mlx->pict[WALL_EAST].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[WALL_EAST].img);
	if (mlx->pict[FLOOR_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[FLOOR_IMG].img);
	if (mlx->pict[CEILING_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pict[CEILING_IMG].img);
}
