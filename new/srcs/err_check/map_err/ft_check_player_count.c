/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:07:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 08:07:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_player_count(t_data **data)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (ft_is_cardinal_char((*data)->map[y][x]))
				player++;
			x++;
		}
		y++;
	}
	if (player == 0)
		ft_clear_data_exit(data, ZEROPMAP);
	if (player > 1)
		ft_clear_data_exit(data, MULTIPMAP);
}
