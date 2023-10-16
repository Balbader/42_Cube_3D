/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:01:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/05 11:01:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "structures.h"
# include "mlx_linux/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/X.h>

/***************************************************************** controller */
int		ft_pressed_key(int key, t_world *world);
int		ft_quit(t_world *world, t_bool exit_value);
int		ft_released_key(int key, t_world *world);

/*********************************************************************** draw */
void	ft_draw(t_world *world);
void	ft_draw_walls(t_world *world);

/****************************************************************** err_check */
void	ft_check_map(t_world *world);
void	ft_check_world(t_world *world);
void	ft_check_parsing(t_world *world, char *msg, int line);
t_bool	ft_check_cell(t_world *world, int i, int j);

/*********************************************************************** init */
void	ft_init_camera(t_world *world);
void	ft_read_file(t_world *world);
t_bool	ft_init_other_stuff(t_world *world);
t_bool	ft_init_screen(t_world *world);
t_bool	ft_init_sprites(t_world *world);
t_world	*ft_init_world(int ac, char **av);

/************************************************************************ map */
void	ft_init_map(t_world *world);
void	ft_init_map_cell(t_world *world, int i, int j, t_bool *parsed_camera);
void	ft_parse_map_row(t_world *world, int i);
void	ft_read_map_row(t_world *world, char *ptr);
t_bool	ft_parse_map(t_world *world);

/********************************************************************* memory */
void	ft_free_textures(t_world *world);
void	ft_free_world(t_world *world);

/****************************************************************** movements */
t_bool	ft_move(t_world *world);
t_bool	ft_rotate(t_world *world);

/******************************************************************** parsing */
void	ft_parse_color(t_world *world, char *ptr, char c, int line_nb);
void	ft_parse_line(t_world *world, char *line, int line_nb, int res);
void	ft_parse_next_line(t_world *world, char *ptr, int line_nb, int res);
void	ft_parse_resolution(t_world *world, char *ptr, int line_nb);
void	ft_parse_texture(t_world *world, char *ptr, int id, int line_nb);

/***************************************************************** raycasting */
void	ft_draw_textured_line(t_world *world, int i, t_texdata data);
void	ft_run_dda(t_world *world, int i, double ray[2]);
t_dda	ft_init_vars(t_world *world, double ray[2]);
t_bool	ft_check_hit(t_world *world, t_dda *vars, t_texdata *data,
		double ray[2]);

/******************************************************************** sprites */
void	ft_sort_sprites(t_world *world);
void	ft_draw_sprites(t_world *world);
void	ft_compute_distances(t_world *world);
void	ft_draw_sprite(t_world *world, t_spritedata data);
void	ft_draw_sprite_line(t_world *world, t_spritedata data, int i,
		int bbox_x[2]);

/********************************************************************** utils */
int		ft_atoi(char *str);
int		ft_char_in_str(char c, char *str);
int		ft_get_screen_pixel(t_img screen, int i, int j);
int		ft_get_tex_color(t_img tex, double u, double v);
int		ft_indexof(char *str, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int start, int len);
char	*ft_remove_spaces(char *str);
char	*ft_trim(char *str);
char	*strjoin(char *line, char *buffer);
bool	ft_manage_buffer(char *buffer);
void	ft_flip_pix(t_world *world);
void	*ft_calloc(int count, int size);
void	ft_load_textures(t_world *world);
void	ft_nb_to_mem(char *dst, int nb, int nb_bytes);
void	ft_set_screen_pixel(t_img screen, int i, int j, int color);
void	ft_write_bmp_header(t_world *world);
t_bool	ft_load_texture(t_world *world, t_img *texture, char *filename);

#endif	
