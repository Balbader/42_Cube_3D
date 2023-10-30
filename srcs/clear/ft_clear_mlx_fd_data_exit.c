/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_mlx_fd_data_exit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 12:50:02 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_mlx_fd_data_exit(t_data **data, void *mlx, int *fd, char *msg)
{
	mlx_destroy_display(mlx);
	ft_close_all_textures(fd);
	ft_clear_data_exit(data, msg);
}
