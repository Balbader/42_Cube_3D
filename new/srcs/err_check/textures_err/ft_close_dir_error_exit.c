/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_dir_error_exit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:46:40 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:46:41 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close_dir_error_exit(t_data **data, int *fd)
{
	if (fd[NORTH] != -1)
	{
		ft_close_all_textures(fd);
		ft_clear_data_exit(data, OPENDIRNOTEX);
	}
	if (fd[SOUTH] != -1)
	{
		ft_close_all_textures(fd);
		ft_clear_data_exit(data, OPENDIRSOTEX);
	}
	if (fd[WEST] != -1)
	{
		ft_close_all_textures(fd);
		ft_clear_data_exit(data, OPENDIRWETEX);
	}
	if (fd[EAST] != -1)
	{
		ft_close_all_textures(fd);
		ft_clear_data_exit(data, OPENDIREATEX);
	}
}
