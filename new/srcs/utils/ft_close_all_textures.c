/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_all_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:25:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 08:25:17 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close_all_textures(int *fd)
{
	if (fd[NORTH] != -1)
		close(fd[NORTH]);
	if (fd[SOUTH] != -1)
		close(fd[SOUTH]);
	if (fd[WEST] != -1)
		close(fd[WEST]);
	if (fd[EAST] != -1)
		close(fd[EAST]);
}
