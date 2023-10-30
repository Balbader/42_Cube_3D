/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_all_dir_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:30:37 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 08:30:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_open_all_dir_textures(t_data **data, int *fd, void *mlx)
{
	fd[NORTH] = open((*data)->north_texture, __O_DIRECTORY | O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, __O_DIRECTORY | O_RDONLY);
	fd[WEST] = open((*data)->west_texture, __O_DIRECTORY | O_RDONLY);
	fd[EAST] = open((*data)->east_texture, __O_DIRECTORY | O_RDONLY);
	if (fd[NORTH] != -1 || fd[SOUTH] != -1 || fd[WEST] != -1 || fd [EAST] != -1)
	{
		mlx_destroy_display(mlx);
		ft_close_dir_error_exit(data, fd);
	}
}
