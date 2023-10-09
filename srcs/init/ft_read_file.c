/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:19:16 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/08 11:19:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_file(t_world *world)
{
	char	*line;
	int		res;
	int		line_nb;

	line_nb = 1;
	res = get_next_line(world->fd, &line);
	while (res >= 0)
	{
		ft_parse_line(world, line, line_nb, res);
		free(line);
		line_nb++;
		if (res == 0)
			break ;
	}
	if (res == -1)
		ft_check_parsing(world, "File is corrupted", 0);
	close(world->fd);
	if (!world->raw_map)
	{
		ft_check_parsing(world, "Map is not defined", 0);
		ft_quit(world, ERROR);
	}
}
