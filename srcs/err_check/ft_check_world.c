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
		parsing_error(world, "Resolution must be defined before the map", 0);
	else if (!world->color_floor)
		parsing_error(world, "Floor color must be defined before the map", 0);
	else if (!world->color_ceiling)
		parsing_error(world, "Ceiling color must be defined before the map", 0);
	else if (!world->textures[N].filename)
		parsing_error(world, "North texture must be defined before the map", 0);
	else if (!world->textures[W].filename)
		parsing_error(world, "West texture must be defined before the map", 0);
	else if (!world->textures[S].filename)
		parsing_error(world, "South texture must be defined before the map", 0);
	else if (!world->textures[E].filename)
		parsing_error(world, "East texture must be defined before the map", 0);
	else if (!world->texture_sprite.filename)
		parsing_error(world, "Sprite texture must be defined before the map",
			0);
}
