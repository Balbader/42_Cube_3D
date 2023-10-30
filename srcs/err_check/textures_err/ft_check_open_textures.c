/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_open_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:43:52 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:43:54 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_open_textures(t_data **data)
{
	void	*mlx;
	int		fd[4];

	ft_bzero_int_tab(fd, 4, 0);
	mlx = mlx_init();
	if (!mlx)
		ft_clear_data_exit(data, MLXINITFAIL);
	ft_open_all_dir_textures(data, fd, mlx);
	ft_bzero_int_tab(fd, 4, 0);
	ft_open_all_textures(data, fd, mlx);
	if (ft_check_texture_size((*data)->north_texture, mlx))
		ft_clear_mlx_fd_data_exit(data, mlx, fd, SIZENOTEX);
	if (ft_check_texture_size((*data)->south_texture, mlx))
		ft_clear_mlx_fd_data_exit(data, mlx, fd, SIZESOTEX);
	if (ft_check_texture_size((*data)->west_texture, mlx))
		ft_clear_mlx_fd_data_exit(data, mlx, fd, SIZEWETEX);
	if (ft_check_texture_size((*data)->east_texture, mlx))
		ft_clear_mlx_fd_data_exit(data, mlx, fd, SIZEEATEX);
	ft_close_all_textures(fd);
	mlx_destroy_display(mlx);
}
