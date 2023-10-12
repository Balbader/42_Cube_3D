/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:58:03 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/08 11:43:17 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_vector2d {
	double	x;
	double	y;
}			t_vector2d;

typedef struct s_map {
	int		width;
	int		height;
	char	**grid;
}			t_map;

typedef struct s_rgb {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct s_player {
	double		speed;
	t_vector2d	coords;
	t_vector2d	dir;
	t_vector2d	plane;
}				t_player;

typedef struct s_window {
	int			height;
	int			width;
}			t_window;

typedef struct s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_dda_output {
	double	dist;
	double	text_x;
	double	text_y;
	int		side;
}		t_dda_output;

typedef struct s_game_data {
	t_rgb		floor_color;
	double		world_scale;
	t_rgb		ceiling_color;
	t_player	player;
	t_window	window;
	t_img		img;
	int			keypress[6];
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	t_map		map;
	void		*mlx;
	void		*mlx_win;
	t_img		n_texture;
	t_img		s_texture;
	t_img		w_texture;
	t_img		e_texture;
	t_img		*texture_to_render;
}				t_game_data;

#endif