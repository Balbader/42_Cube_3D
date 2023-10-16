/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:37:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:37:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_load_textures(t_world *world)
{
	t_side	side;

	side = N;
	while (side <= E)
	{
		ft_load_texture(world, &(world->textures[side]),
			world->textures[side].filename);
		side++;
	}
	ft_load_texture(world, &(world->texture_sprite),
		world->texture_sprite.filename);
}
