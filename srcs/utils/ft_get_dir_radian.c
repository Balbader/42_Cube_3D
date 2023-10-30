/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_radian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:08:10 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 08:08:11 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_dir_radian(t_data **data, char player_pos)
{
	if (player_pos == 'N')
		(*data)->player_dir_radian = M_PI / 2;
	else if (player_pos == 'S')
		(*data)->player_dir_radian = 3 * (M_PI / 2);
	else if (player_pos == 'W')
		(*data)->player_dir_radian = M_PI;
	else if (player_pos == 'E')
		(*data)->player_dir_radian = 0.0;
}
