/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:24:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:24:26 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_side(t_data **data, int x, int y, int dir)
{
	if (direction == NORTH && (*data)->map[y - 1][x] == ' ')
		ft_clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
	if (direction == SOUTH && (*data)->map[y + 1][x] == ' ')
		ft_clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
	if (direction == WEST && (*data)->map[y][x - 1] == ' ')
		ft_clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
	if (direction == EAST && (*data)->map[y][x + 1] == ' ' )
		ft_clear_data_nclosedmap_exit(data, y, NCLOSEDMAP);
}
