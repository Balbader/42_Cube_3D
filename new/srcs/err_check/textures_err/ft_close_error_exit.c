/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_error_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:47:57 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:47:58 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close_error_exit(t_data **data, int *fd)
{
	ft_close_all_textures(fd);
	if (fd[NORTH] == -1)
		ft_clear_data_exit(data, OPENNOTEX);
	if (fd[SOUTH] == -1)
		ft_clear_data_exit(data, OPENSOTEX);
	if (fd[WEST] == -1)
		ft_clear_data_exit(data, OPENWETEX);
	if (fd[EAST] == -1)
		ft_clear_data_exit(data, OPENEATEX);
}
