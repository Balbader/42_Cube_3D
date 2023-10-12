/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:18:09 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:31:47 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X.h>
# include <keysym.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"
# include "cub3d_structs.h"
# include "cub3d_constants.h"

int		parser_map_check(char **grid);
int		parser_mapcheck_look_around(char **grid, int i, int j);
int		parser_get_map(t_game_data *game_data, char *map_path);
int		parser_error_check(t_game_data *game_data, char *map_path);
int		get_texture_id(char *line);
int		is_nsew(char c);
int		img_init(t_game_data *data);
int		game_data_init(t_game_data *data);
void	game_data_destroy(t_game_data *game_data);
int		game_loop(t_game_data *game_data);
int		game_exit(t_game_data *game_data);
int		render_frame(t_game_data *game_data);
void	dda_get_dist(t_game_data *game_data, t_vector2d *ray, \
t_dda_output *ddoutput);
void	setup_hooks(t_game_data *game_data);
int		keypress_handler(int keysym, t_game_data *game_data);
int		keyrelease_handler(int keysym, t_game_data *game_data);
int		mouse_handler(int mouseX, int mouseY, t_game_data *game_data);
int		map_out_of_bounds(t_game_data *data, double x, double y);
void	render_vert(t_game_data *game_data, int x, t_vector2d *wall, \
t_dda_output *ddoutput);
void	player_move(t_game_data *data, double x, double y);
int		put_map_error(char *map_path);
int		put_error(int error);

#endif