/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:29:16 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/08 11:29:19 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_init_sprites(t_world *world)
{
	int		i;
	int		j;
	int		index;

	world->sprites = ft_calloc(world->nb_sprites, sizeof(t_sprite));
	if (!world->sprites)
		return (FALSE);
	index = 0;
	i = 0;
	while (i < world->map_height)
	{
		j = 0;
		while (j < world->map_width)
		{
			if (world->map[i][j] == 2)
			{
				world->sprites[index].texture = world->texture_sprite;
				world->sprites[index].pos[0] = i;
				world->sprites[index].pos[1] = j;
				index++;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
