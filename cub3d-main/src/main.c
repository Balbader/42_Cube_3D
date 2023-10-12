/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:54:58 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 12:49:23 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static int	error_message(int error_status)
{
	if (error_status == E_OPEN_MAP)
		return (printf("info : open map\n"), -1);
	if (error_status == E_EMPTY_LINE)
		return (printf("info : empty line\n"), -1);
	if (error_status == E_INVALID_CHAR)
		return (printf("info : invalid character\n"), -1);
	if (error_status == E_SEVERAL_CHAR)
		return (printf("info : 1 player max, several players in the map\n"), -1);
	if (error_status == E_NO_CHAR)
		return (printf("info : 1 player required, no player in the map\n"), -1);
	if (error_status == E_SYNTAX_ERROR)
		return (printf("info : syntax error\n"), -1);
	return (-1);
}
*/
int	main(int argc, char *argv[])
{
	t_game_data	game_data;
	int			error_status;

	if (argc != 2)
		return (printf("Usage : %s map_path.cub\n", argv[0]), 1);
	game_data.north_texture = NULL;
	game_data.south_texture = NULL;
	game_data.east_texture = NULL;
	game_data.west_texture = NULL;
	game_data.map.grid = NULL;
	game_data.mlx = NULL;
	game_data.mlx_win = NULL;
	error_status = parser_get_map(&game_data, argv[1]);
	if (error_status == E_SYNTAX_ERROR)
		return (game_data_destroy(&game_data), 1);
	error_status = parser_map_check(game_data.map.grid);
	if (error_status != E_OK)
		return (game_data_destroy(&game_data), 1);
	if (game_data_init(&game_data) != 0)
		return (game_data_destroy(&game_data), 1);
	setup_hooks(&game_data);
	mlx_loop(game_data.mlx);
	game_data_destroy(&game_data);
	return (0);
}
