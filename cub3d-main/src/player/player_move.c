/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:12:06 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/07 17:11:54 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move(t_game_data *data, double x, double y)
{
	if (!map_out_of_bounds(data, data->player.coords.x + x, \
	data->player.coords.y))
		data->player.coords.x += x;
	if (!map_out_of_bounds(data, data->player.coords.x, \
	data->player.coords.y + y))
		data->player.coords.y += y;
}
