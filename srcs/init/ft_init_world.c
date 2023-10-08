/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:21:10 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/08 11:21:12 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_world	*ft_init_world(int ac, char **av)
{
	t_world	*world;

	world = (t_world *)ft_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	world->fd = open(argv[1], O_RDONLY);
	if (argc < 2)
		ft_check_parsin(world, "No scene file specified", 0);
	else if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0)
		ft_check_paring(world, "File is invalid: should have extension .cub",
			0);
	else if (world->fd < 0)
		ft_check_parsing(world, "File does not exist", 0);
	else
		ft_read_file(world);
	if (world->error)
	{
		if (world->raw_map)
			free(world->raw_map);
		quit(world, ERROR);
	}
	world->save = ((argc > 2) && (ft_strcmp(argv[2], "--save") == 0));
	if (!ft_init_other_stuff(world))
		return (NULL);
	return (world);
}