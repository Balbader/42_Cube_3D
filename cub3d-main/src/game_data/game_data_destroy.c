/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:38:17 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:21:05 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_data_destroy_alt(t_game_data *game_data)
{
	int	i;

	i = 0;
	while (game_data->map.grid && game_data->map.grid[i])
		free(game_data->map.grid[i++]);
	if (game_data->map.grid)
		free(game_data->map.grid);
	game_data->map.grid = NULL;
	if (game_data->mlx && game_data->mlx_win)
		mlx_destroy_display(game_data->mlx);
	game_data->mlx_win = NULL;
	if (game_data->mlx)
		free(game_data->mlx);
	game_data->mlx = NULL;
}

void	game_data_destroy(t_game_data *game_data)
{
	if (game_data->north_texture)
		free(game_data->north_texture);
	game_data->north_texture = NULL;
	if (game_data->south_texture)
		free(game_data->south_texture);
	game_data->south_texture = NULL;
	if (game_data->east_texture)
		free(game_data->east_texture);
	game_data->east_texture = NULL;
	if (game_data->west_texture)
		free(game_data->west_texture);
	game_data->west_texture = NULL;
	game_data_destroy_alt(game_data);
}
