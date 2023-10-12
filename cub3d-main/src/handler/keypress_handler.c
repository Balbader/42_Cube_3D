/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:11:05 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/07 17:04:02 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* QWERTY
 - left arrow : 65363
 - right arrow : 65361
 - w : 119
 - a : 97
 - s : 115
 - d : 100
*/

static void	rotate_direction(t_game_data *game_data, double angle)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = game_data->player.dir.x;
	old_dir_y = game_data->player.dir.y;
	old_plane_x = game_data->player.plane.x;
	old_plane_y = game_data->player.plane.y;
	game_data->player.dir.x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	game_data->player.dir.y = old_dir_x * sin(angle) + old_dir_y * cos(angle);
	game_data->player.plane.x = old_plane_x * cos(angle) - old_plane_y * \
	sin(angle);
	game_data->player.plane.y = old_plane_x * sin(angle) + old_plane_y * \
	cos(angle);
}

static void	handle_keypress(t_game_data *game_data, int keypress)
{
	double	dx;
	double	dy;
	double	speed;

	dx = game_data->player.dir.x;
	dy = game_data->player.dir.y;
	speed = game_data->player.speed;
	if (keypress == KEY_RLEFT)
		rotate_direction(game_data, 0.2);
	else if (keypress == KEY_RRIGHT)
		rotate_direction(game_data, -0.2);
	else if (keypress == KEY_FORWARD)
		player_move(game_data, dx * speed, dy * speed);
	else if (keypress == KEY_LEFT)
		player_move(game_data, (-dx * cos(1.5707) + dy * sin(1.5707)) * \
		speed, (-dx * sin(1.5707) - dy * cos(1.5707)) * speed);
	else if (keypress == KEY_BACKWARD)
		player_move(game_data, -dx * speed, -dy * speed);
	else if (keypress == KEY_RIGHT)
		player_move(game_data, (dx * cos(1.5707) - dy * sin(1.5707)) * \
		speed, (dx * sin(1.5707) + dy * cos(1.5707)) * speed);
}

int	keypress_handler(int keysym, t_game_data *game_data)
{
	int	i;

	if (keysym == 0xff1b)
		return (game_exit(game_data), 0);
	else if (keysym == 65363)
		game_data->keypress[KEY_RLEFT] = 1;
	else if (keysym == 65361)
		game_data->keypress[KEY_RRIGHT] = 1;
	else if (keysym == 119)
		game_data->keypress[KEY_FORWARD] = 1;
	else if (keysym == 97)
		game_data->keypress[KEY_LEFT] = 1;
	else if (keysym == 115)
		game_data->keypress[KEY_BACKWARD] = 1;
	else if (keysym == 100)
		game_data->keypress[KEY_RIGHT] = 1;
	else
		printf("key pressed : %d\n", keysym);
	i = -1;
	while (++i < 6)
		if (game_data->keypress[i])
			handle_keypress(game_data, i);
	render_frame(game_data);
	return (0);
}
