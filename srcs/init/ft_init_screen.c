/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:51:12 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/08 11:51:14 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_init_screen(t_world *world)
{
	world->screen.ptr = mlx_new_image(world->mlx.ptr,
			world->scr_width, world->scr_height);
	if (!world->screen.ptr)
		return (FALSE);
	world->screen.data = mlx_get_data_addr(world->screen.ptr,
			&(world->screen.bpp), &(world->screen.size_line),
			&(world->screen.endian))));
	if (!world->screen.data)
		return (FALSE);
	return (TRUE);
}
