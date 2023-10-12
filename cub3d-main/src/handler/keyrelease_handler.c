/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:30:05 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:46 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyrelease_handler(int keysym, t_game_data *game_data)
{
	if (keysym == 65363)
		game_data->keypress[KEY_RLEFT] = 0;
	else if (keysym == 65361)
		game_data->keypress[KEY_RRIGHT] = 0;
	if (keysym == 119)
		game_data->keypress[KEY_FORWARD] = 0;
	else if (keysym == 97)
		game_data->keypress[KEY_LEFT] = 0;
	else if (keysym == 115)
		game_data->keypress[KEY_BACKWARD] = 0;
	else if (keysym == 100)
		game_data->keypress[KEY_RIGHT] = 0;
	return (0);
}
