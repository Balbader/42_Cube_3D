/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:10:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 08:10:12 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_player_info(t_data **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (ft_is_cardinal_char((*data)->map[y][x]))
			{
				(*data)->player_x = x;
				(*data)->player_y = y;
				(*data)->player_dir = (*data)->map[y][x];
				ft_get_dir_radian(data, (*data)->map[y][x]);
			}
			x++;
		}
		y++;
	}
}
