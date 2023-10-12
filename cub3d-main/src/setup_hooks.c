/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:02:28 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/07 15:50:42 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_hooks(t_game_data *game_data)
{
	mlx_loop_hook(game_data->mlx, &game_loop, game_data);
	mlx_hook(game_data->mlx_win, KeyPress, KeyPressMask, &keypress_handler, \
	game_data);
	mlx_hook(game_data->mlx_win, KeyRelease, KeyReleaseMask, \
	&keyrelease_handler, game_data);
	mlx_hook(game_data->mlx_win, VisibilityNotify, VisibilityChangeMask, \
	&render_frame, game_data);
	mlx_mouse_hook(game_data->mlx_win, &mouse_handler, game_data);
	mlx_hook(game_data->mlx_win, ClientMessage, StructureNotifyMask, \
	&game_exit, game_data);
}
