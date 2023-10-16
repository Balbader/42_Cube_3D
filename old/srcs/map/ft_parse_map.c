/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:27:35 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:27:36 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_parse_map(t_world *world)
{
	int		i;
	char	*ptr;

	i = 0;
	world->map_height = 0;
	while (world->raw_map[i])
	{
		if (world->raw_map[i] == '\n')
			world->map_height++;
		i++;
	}
	world->char_map = ft_calloc(world->map_height, sizeof(char *));
	if (!world->char_map)
		return (FALSE);
	ptr = world->raw_map;
	i = 0;
	world->map_width = 0;
	while (i < world->map_height)
		ft_parse_map_row(world, i++);
	free(ptr);
	ft_init_map(world);
	ft_check_map(world);
	if (world->error)
		ft_quit(world, ERROR);
	return (TRUE);
}
