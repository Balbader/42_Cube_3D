/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:02:54 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:02:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_sprites(t_world *world)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < world->nb_sprites)
	{
		j = 0;
		while (j < world->nb_sprites - i - 1)
		{
			if (world->sprites[i].distance < world->sprites[i + 1].distance)
			{
				tmp = world->sprites[i];
				world->sprites[i] = world->sprites[i + 1];
				world->sprites[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
