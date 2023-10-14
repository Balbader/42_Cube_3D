/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:43:59 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 15:44:00 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	if (!map)
		return ;
	while (map[y])
	{
		printf(YELLOW "[" RESET "%3d" YELLOW "] " GREEN "[" RESET, y);
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				printf(RED "%c" RESET, map[y][x]);
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' \
				|| map[y][x] == 'E')
				printf(YELLOW "%c" RESET, map[y][x]);
			else
				printf("%c", map[y][x]);
			x++;
		}
		printf(GREEN "]" RESET "\n");
		y++;
	}
	printf("\n");
}
