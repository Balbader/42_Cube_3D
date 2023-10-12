/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:13:23 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:15:22 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_exit(t_game_data *game_data)
{
	mlx_destroy_image(game_data->mlx, game_data->img.mlx_img);
	if (game_data->n_texture.mlx_img)
		mlx_destroy_image(game_data->mlx, game_data->n_texture.mlx_img);
	if (game_data->s_texture.mlx_img)
		mlx_destroy_image(game_data->mlx, game_data->s_texture.mlx_img);
	if (game_data->e_texture.mlx_img)
		mlx_destroy_image(game_data->mlx, game_data->e_texture.mlx_img);
	if (game_data->w_texture.mlx_img)
		mlx_destroy_image(game_data->mlx, game_data->w_texture.mlx_img);
	mlx_destroy_window(game_data->mlx, game_data->mlx_win);
	return (1);
}
