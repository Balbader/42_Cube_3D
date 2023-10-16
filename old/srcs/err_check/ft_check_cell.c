/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:06:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:06:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_check_cell(t_world *world, int i, int j)
{
	return (!((i == 0 || j == 0 || i == world->map_height - 1
				|| j == world->map_width - 1 || world->map[i - 1][j] == -1
			|| world->map[i + 1][j] == -1 || world->map[i][j - 1] == -1
		|| world->map[i][j + 1] == -1)
		&& world->map[i][j] != 1 && world->map[i][j] != -1));
}
