/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_out_of_bounds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:15:32 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/04 17:47:36 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_out_of_bounds(t_game_data *data, double x, double y)
{
	int	x_round;
	int	y_round;

	x_round = (int) x;
	y_round = (int) y;
	if (y_round < 0 || y_round >= data->map.height
		|| x_round < 0 || x_round >= (int) ft_strlen(data->map.grid[y_round])
		|| data->map.grid[y_round][x_round] == ' '
		|| data->map.grid[y_round][x_round] == '1')
	{
		return (1);
	}
	return (0);
}
