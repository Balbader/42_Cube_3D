/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_distances.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:02:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:02:13 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_compute_distances(t_world *world)
{
	int	i;

	i = 0;
	while (i < world->nb_sprites)
	{
		world->sprites[i].distance =
			pow(world->pos[0] - world->sprites[i].pos[0], 2)
			+ pow(world->pos[1] - world->sprites[i].pos[1], 2);
		i++;
	}
}
