/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:49:49 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:49:50 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_next_line(t_world *world, char *ptr, int line_nb, int res)
{
	char	*no_spaces;

	no_spaces = ft_remove_spaces(ptr);
	if (ft_strlen(no_spaces) > 0 && ft_indexof("012NWSE", *no_spaces) >= 0)
		ft_read_map_row(world, ptr);
	else if (world->raw_map && res > 0)
		ft_parsing_error(world, "Map contains an empty line", line_nb);
	free(no_spaces);
}
