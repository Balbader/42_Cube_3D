/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:44:23 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:44:27 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_color(t_world *world, char *ptr, char c, int line_nb)
{
	int		color;
	int		i;

	if (c == 'F' && world->color_floor)
		ft_parsing_error(world, "Floor color was already defined", line_nb);
	if (c == 'C' && world->color_ceiling)
		ft_parsing_error(world, "Ceiling color was already defined", line_nb);
	i = 0;
	color = 0;
	while (i++ < 3)
	{
		while (*ptr <= ' ')
			ptr++;
		if (*ptr > '9' || *ptr < '0')
			ft_parsing_error(world, "Color is invalid", line_nb);
		color = (color << 8) + ft_atoi_easy(ptr);
		while (*ptr >= '0' && *ptr <= '9')
			ptr++;
		(*ptr == ',' || i == 3) ? ptr++
			: ft_parsing_error(world, "Color is invalid", line_nb);
	}
	if (c == 'F')
		world->color_floor = color;
	else
		world->color_ceiling = color;
}
