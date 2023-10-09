/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_bmp_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:32:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:32:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_write_bmp_header(t_world *world)
{
	char	header[54];

	header[0] = 'B';
	header[1] = 'M';
	nb_to_mem(&header[2], 54 + world->nb_pixels, 4);
	nb_to_mem(&header[6], 0, 4);
	nb_to_mem(&header[10], 54, 4);
	nb_to_mem(&header[14], 40, 4);
	nb_to_mem(&header[18], world->scr_width, 4);
	nb_to_mem(&header[22], world->scr_height, 4);
	nb_to_mem(&header[26], 1, 2);
	nb_to_mem(&header[28], world->screen.bpp, 2);
	nb_to_mem(&header[30], 0, 4);
	nb_to_mem(&header[34], world->nb_pixels, 4);
	nb_to_mem(&header[38], 0, 16);
	write(world->fd_save, header, 54);
}
