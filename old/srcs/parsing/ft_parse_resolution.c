/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:42:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:42:51 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_resolution(t_world *world, char *ptr, int line_nb)
{
	if (world->scr_width)
		ft_check_parsing(world, "Resolution was already defined", line_nb);
	while (*ptr <= ' ')
		ptr++;
	world->scr_width = ft_atoi(ptr);
	while (*ptr >= '0' && *ptr <= '9')
		ptr++;
	while (*ptr <= ' ')
		ptr++;
	world->scr_height = ft_atoi(ptr);
	while (*ptr >= '0' && *ptr <= '9')
		ptr++;
	ptr = ft_remove_spaces(ptr);
	if (world->scr_width == 0 || world->scr_height == 0 || ft_strlen(ptr) > 0)
		ft_check_parsing(world, "Resolution is invalid", line_nb);
	world->scr_width = world->scr_width > 2560 ? 2560 : world->scr_width;
	world->scr_height = world->scr_height > 1440 ? 1440 : world->scr_height;
	world->scr_width = world->scr_width < 100 ? 100 : world->scr_width;
	world->scr_height = world->scr_height < 100 ? 100 : world->scr_height;
	free(ptr);
}
