/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:04:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:04:12 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_world(t_world *world)
{
	if (!world->scr_width)
		ft_check_parsing(world, "Resolution must be defined before the map", 0);
	else if (!world->color_floor)
		ft_check_parsing(world, "Floor color must be defined before the map", 0);
	else if (!world->color_ceiling)
		ft_check_parsing(world, "Ceiling color must be defined before the map", 0);
	else if (!world->textures[N].filename)
		ft_check_parsing(world, "North texture must be defined before the map", 0);
	else if (!world->textures[W].filename)
		ft_check_parsing(world, "West texture must be defined before the map", 0);
	else if (!world->textures[S].filename)
		ft_check_parsing(world, "South texture must be defined before the map", 0);
	else if (!world->textures[E].filename)
		ft_check_parsing(world, "East texture must be defined before the map", 0);
	else if (!world->texture_sprite.filename)
		ft_check_parsing(world, "Sprite texture must be defined before the map", 0);
}
