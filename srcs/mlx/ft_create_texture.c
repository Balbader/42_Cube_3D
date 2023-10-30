/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:58:31 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:58:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_create_texture(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	if (!mlx->win_ptr)
		return (ft_free_mlx(mlx));
	if (ft_xpm_file_and_addr(mlx->mlx_ptr, &mlx->pict[IMAGE]))
		return (ft_free_mlx(mlx));
	if (ft_xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->north_texture,
			&mlx->pict[WALL_NORTH]))
		return (ft_free_mlx(mlx));
	if (ft_xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->south_texture,
			&mlx->pict[WALL_SOUTH]))
		return (ft_free_mlx(mlx));
	if (ft_xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->west_texture,
			&mlx->pict[WALL_WEST]))
		return (ft_free_mlx(mlx));
	if (ft_xpm_texture_and_addr(mlx->mlx_ptr, mlx->data->east_texture,
			&mlx->pict[WALL_EAST]))
		return (ft_free_mlx(mlx));
}
