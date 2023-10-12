/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:25:54 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:19:35 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	if_e_or_w(t_game_data *data, int x, int y)
{
	if (data->map.grid[y][x] == 'E')
	{
		data->player.dir.x = 1;
		data->player.dir.y = 0;
		data->player.plane.x = 0;
		data->player.plane.y = -CAMERA_PLANE;
	}
	if (data->map.grid[y][x] == 'W')
	{
		data->player.dir.x = -1;
		data->player.dir.y = 0;
		data->player.plane.x = 0;
		data->player.plane.y = CAMERA_PLANE;
	}
}

static void	if_nsew(t_game_data *data, int x, int y)
{
	if_e_or_w(data, x, y);
	if (data->map.grid[y][x] == 'N')
		data->player.dir.y = -1;
	if (data->map.grid[y][x] == 'N')
		data->player.plane.x = CAMERA_PLANE;
	if (data->map.grid[y][x] == 'S')
		data->player.dir.y = 1;
	if (data->map.grid[y][x] == 'S')
		data->player.plane.x = -CAMERA_PLANE;
	if (data->map.grid[y][x] == 'N' || data->map.grid[y][x] == 'S')
		data->player.dir.x = 0;
	if (data->map.grid[y][x] == 'N' || data->map.grid[y][x] == 'S')
		data->player.plane.y = 0;
	if (is_nsew(data->map.grid[y][x]) == 1)
	{
		data->player.coords.x = (double) x;
		data->player.coords.y = (double) y;
	}
}

static void	init_player_coords(t_game_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if_nsew(data, x, y);
			x++;
		}
		y++;
	}
}

static void	init_keypress(t_game_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->keypress[i] = 0;
		i++;
	}
}

int	game_data_init(t_game_data *data)
{
	data->world_scale = WORLD_SCALE;
	init_player_coords(data);
	init_keypress(data);
	data->player.speed = 0.2;
	data->window.height = WIN_HEIGHT;
	data->window.width = WIN_WIDTH;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putstr_fd("Could not initialize mlx\n", 2), E_NULLPTR);
	data->mlx_win = mlx_new_window(data->mlx, data->window.width, \
	data->window.height, WIN_TITLE);
	if (!data->mlx_win)
	{
		free(data->mlx);
		return (ft_putstr_fd("Could not initialize mlx window\n", 2), E_NULLPTR);
	}
	return (img_init(data));
}
