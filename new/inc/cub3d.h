/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:27:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:27:14 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/****************************************************************** err_check */
/* duplicates_err */
void	ft_check_cardinal_duplicates(t_list **list, int *dup, char *str, int i);
void	ft_check_color_duplicates(t_list **list, int *dup, char *str, int i);
void	ft_check_list_duplicates(t_list **list);
void	ft_check_missing_lines(t_list **list, int *dup);

/* map_err */
int		ft_is_not_only_one_or_space_str(char *str);
void	ft_check_closed_map(t_data **data);
void	ft_check_first_last_char(t_data **data);
void	ft_check_inner_map(t_data **data);
void	ft_check_side(t_data **data, int x, int y, int dir);

/* syntax_err */
int		ft_check_cardinal_syntax(char *str);
int		ft_check_fc_syntax(char *str);
void	ft_check_last_element(t_list **list);
void	ft_check_list_syntax(t_list **list);
void	ft_check_splitted_map(t_list **list);

/* textures_err */
int		ft_check_texture_size(char *path, void *mlx);
void	ft_check_open_textures(t_data **data);
void	ft_check_textures_extensions(t_data **data);
void	ft_close_dir_error_exit(t_data **data, int *fd);
void	ft_close_error_exit(t_data **data, int *fd);

/********************************************************************** clear */
void	ft_clear_all_exit(t_data **data, t_list **list, char *msg);
void	ft_clear_data(t_data **data);
void	ft_clear_data_exit(t_data **data, char *msg);
void	ft_clear_data_nclosedmap_exit(t_data **data, int i, char *msg);
void	ft_clear_data_syntax_exit(t_data **data, int i, char *line, char *msg);
void	ft_clear_list_exit(t_list **list, char *msg);
void	ft_clear_list_free_line_exit(t_list **list, char *line);
void	ft_clear_list_syntax_exit(t_list **list, int i, char *line, char *msg);
void	ft_clear_mlx_fd_data_exit(t_data **data, void *mlx, int *fd, char *msg);

/*********************************************************************** free */
void	ft_free_array(char **arr);
void	ft_free_mlx(t_mlx *mlx);
void	ft_free_texture(t_mlx *mlx);

/************************************************************************ mlx */
int		ft_close(t_mlx *mlx);
int		ft_key_hook(int key, t_mlx *mlx);
int		ft_xpm_file_and_addr(void *mlx_ptr, t_img *img);
int		ft_xpm_texture_and_addr(void *mlx_ptr, char *txt_name, t_img *img);
void	ft_create_texture(t_mlx *mlx);
void	ft_mlx_print_line(t_mlx *mlx, int const a[2], int const b[2], \
		int const color);
void	ft_choose_h_or_v(t_rayon *rayon, double dist[2], double end_pos[2][2]);
void	ft_print_min_map(t_mlx *mlx);
void	ft_start_mlx(t_data *data);
void	ft_fill_floor_wall_and_ceiling(t_mlx *const mlx, \
		t_rayon const *const rayon, float const line_h, int const x);
void	ft_print_3d(t_mlx *const mlx, t_rayon *const rayon, double ra, int *x);
double	ft_dist(double ax, double ay, double bx, double by);
void	ft_print_nord(t_img *const img[2], t_rayon const *const rayon, \
		float i[4]);
void	ft_print_south(t_img *const img[2], t_rayon const *const rayon, \
		float i[4]);
void	ft_print_west(t_img *const img[2], t_rayon const *const rayon, \
		float i[4]);
void	ft_print_east(t_img *const img[2], t_rayon const *const rayon, \
		float i[4]);

/***************************************************************** raycasting */
double	ft_horizontal_check(t_mlx *mlx, double re, double end_pos[2]);
double	ft_horizontal_while(t_mlx *mlx, double ray[2], double offset[2]);
double	ft_vertical_check(t_mlx *mlx, double ra, double end_pos[2]);
double	ft_vertical_while(t_mlx *mlx, double rayon[2], \
		double offset, double end_pos[2]);

#endif // !CUB3D_H
