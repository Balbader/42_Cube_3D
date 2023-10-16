/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:51:35 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:51:37 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_line(t_world *world, char *line, int line_nb, int res)
{
	char	*ptr;

	ptr = line;
	while (*ptr && *ptr <= ' ')
		ptr++;
	if (*ptr == 'R')
		ft_parse_resolution(world, ptr + 1, line_nb);
	else if (*ptr == 'N' && *(ptr + 1) == 'O')
		ft_parse_texture(world, ptr + 2, N, line_nb);
	else if (*ptr == 'S' && *(ptr + 1) == 'O')
		ft_parse_texture(world, ptr + 2, S, line_nb);
	else if (*ptr == 'W' && *(ptr + 1) == 'E')
		ft_parse_texture(world, ptr + 2, W, line_nb);
	else if (*ptr == 'E' && *(ptr + 1) == 'A')
		ft_parse_texture(world, ptr + 2, E, line_nb);
	else if (*ptr == 'F' || *ptr == 'C')
		ft_parse_color(world, ptr + 1, *ptr, line_nb);
	else if (*ptr == 'S')
		ft_parse_texture(world, ptr + 1, 4, line_nb);
	else
		ft_parse_next_line(world, line, line_nb, res);
}
