/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:01:40 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/05 11:01:42 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef int			t_bool;

typedef enum		e_side
{
	N,
	W,
	S,
	E
}					t_side;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_dda
{
	double	side_dist[2];
	double	delta_dist[2];
	double	wall_dist;
	int		map_pos[2];
	int		step[2];
}					t_dda;

typedef struct		s_texdata
{
	double	wall_dist;
	double	wall_x;
	int		line_height;
	t_side	side;
}					t_texdata;

typedef struct		s_spritedata
{
	double	transform[2];
	int		sprite_x;
	int		sprite_size;
	int		index;
}					t_spritedata;

typedef struct		s_ctrls
{
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_bool	left;
	t_bool	right;
}					t_ctrls;

typedef struct		s_img
{
	char	*filename;
	void	*ptr;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		size_line;
	t_bool	endian;
}					t_img;

typedef struct		s_sprite
{
	int		pos[2];
	double	distance;
	t_img	texture;
}					t_sprite;

typedef struct		s_world
{
	t_mlx			mlx;
	int				fd;
	t_bool			error;
	int				scr_width;
	int				scr_height;
	int				map_width;
	int				map_height;
	char			*raw_map;
	char			**char_map;
	int				**map;
	int				color_floor;
	int				color_ceiling;
	t_img			textures[4];
	t_img			texture_sprite;
	int				nb_sprites;
	t_sprite		*sprites;
	t_img			screen;
	t_ctrls			ctrls;
	int				nb_pixels;
	double			*depth_buffer;
	double			pos[2];
	double			dir[2];
	double			cam_plane[2];
	t_side			cam_dir;
	t_bool			save;
	int				fd_save;
}					t_world;

#endif	
