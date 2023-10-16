/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:10:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:10:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(t_world *world)
{
	int		i;
	int		j;

	i = 0;
	while (i < world->map_height)
	{
		j = 0;
		while (j < world->map_width)
		{
			if (!ft_check_cell(world, i, j))
				ft_check_parsing(world, "Map is invalid", 0);
			j++;
		}
		i++;
	}
}
