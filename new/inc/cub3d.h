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
void	ft_check_player_count(t_data **data);
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
void	ft_check_value_limits(t_data **data, t_list **list, \
			char **array, char **str);

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

/*********************************************************************** fill */
void	ft_fill_data(t_data **data, t_list **list);
void	ft_fill_map(t_data **data, t_list **list);
void	ft_fill_list(int fd, t_list **list);
void	ft_fill_texture(t_data **data, t_list **list, char **dest, char *src);
void	ft_fill_rgb(t_data **data, t_list **list, int *dst, char *src);

/************************************************************************ gnl */
int	get_next_line(int fd, char **line);

/*********************************************************************** init */
void	ft_find_player_pos(char **tmp, t_mlx *mlx);
void	ft_init_player(t_mlx *mlx, int *pos);
void	ft_init_map(t_data **data, t_list **list);
void	ft_init_data(t_data **data, t_list **list);
bool	ft_is_player(char c, double *angle);

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

/******************************************************************** parsing */
void	ft_check_ac(int ac, char **av);
void	ft_parsing(int ac, char **av, t_data **data);


/***************************************************************** raycasting */
double	ft_horizontal_check(t_mlx *mlx, double re, double end_pos[2]);
double	ft_horizontal_while(t_mlx *mlx, double ray[2], double offset[2]);
double	ft_vertical_check(t_mlx *mlx, double ra, double end_pos[2]);
double	ft_vertical_while(t_mlx *mlx, double rayon[2], \
		double offset, double end_pos[2]);

/***************************************************************** utils */
int		ft_lst_size(t_list *lst);
int		ft_atoi(char *str);
int		ft_atoi_base(char *str, int str_base);
int		ft_nbrlen(char *str);
int		ft_create_trgb(int t, int r, int g, int b);
int		ft_isdigit(char c);
int		ft_is_color_char(char c);
int		ft_is_cardinal_char(char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_is_map_str(char *str);
int		ft_check_extension(char *str, char *ext);
int		ft_check_close(int fd, t_list *list);
int		ft_get_hexa_rgb_values(t_data **data, t_list **list, char **str);
char	*ft_copy_str(char *dest, char *src);
char	**ft_split(t_data **data, t_list **list, char *str, char c);
char	*ft_strchr(char *str, char c);
char	*ft_sub_trim_str(char *str, char *set);
char	*ft_strndup(char *str, int n);
void	ft_get_map_size(t_data **data, t_list **list);
void	*ft_ternary(int const cond, void *valid_1, void *valid_2);
void	ft_print_array(char **arr);
void	ft_print_map(char **map);
void	ft_print_data(t_data *data);
void	ft_print_list(t_list *list);
void	ft_print_exit_error(char *msg);
void	ft_lst_clear(t_list **lst);
void	ft_lstlast(t_list *lst);
void	ft_bzero_int_tab(int *tab, int tab_size, int value);
void	*ft_memset(void *b, int c, int len);
void	ft_get_dir_radian(t_data **data, char player_pos);
void	ft_close_all_textures(int *fd);
void	ft_get_player_info(t_data **data);
void	ft_open_all_textures(t_data **data, int *fd, void *mlx);
void	ft_open_all_dir_textures(t_data **data, int *fd, void *mlx);
void	ft_check_open(char *filename, int *fd);
t_list	*ft_lst_create(char *line);
t_list	*ft_lst_addback(t_list **lst, t_list *elem);

#endif // !CUB3D_H
