/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_last_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:23:33 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:23:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_first_last_char(t_data **data)
{
	int		y;
	char	**map;
	int		width;

	y = 1;
	map = (*data)->map;
	width = (*data)->map_width;
	while (y < (*data)->map_height - 1)
	{
		if ((map[y][0] == '0' || map[y][width - 1] == '0') || \
			(map[y][0] == 'N' || map[y][width - 1] == 'N') || \
			(map[y][0] == 'S' || map[y][width - 1] == 'S') || \
			(map[y][0] == 'E' || map[y][width - 1] == 'E') || \
			(map[y][0] == 'W' || map[y][width - 1] == 'W'))
			ft_clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
		y++;
	}
}
