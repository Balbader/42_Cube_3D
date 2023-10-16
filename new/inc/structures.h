/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:26:42 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 09:26:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;
typedef struct s_list	t_list;
typedef struct s_rayon	t_rayon;

struct s_data
{
	char	**map;
	int		map_height;
	int		map_width;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb;
	int		ceiling_rgb;
	int		player_x;
	int		player_y;
	char	player_dir;
	float	player_dir_radian;
};

struct s_list
{
	char	*line;
	int		line_size;
	int		type;
	t_list	*next;
};

struct s_rayon
{
	float	dist;
	double	angle;
	int		type;
	double	end_pos[2];
};

struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	pict[MAX_IMG];
	double	player[MAX_POS];
	double	delta[2];
	t_rayon	rayon[WIDTH];
	t_data	*data;
};

#endif // !STRUCTURES_H
