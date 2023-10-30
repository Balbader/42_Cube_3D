/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inner_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:19:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:19:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_inner_map(t_data **data)
{
	int	x;
	int	y;

	y = 1;
	while (y < (*data)->map_height)
	{
		x = 1;
		while (x < (*data)->map_width)
		{
			if ((*data)->map[y][x] == '0')
			{
				ft_check_side(data, x, y, NORTH);
				ft_check_side(data, x, y, SOUTH);
				ft_check_side(data, x, y, WEST);
				ft_check_side(data, x, y, EAST);
			}
			x++;
		}
		y++;
	}
}
