/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:54:46 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 06:54:48 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief	Function find the player position
 * 			fill the struct with the value
 *
 * @param	char**	to parse the map and find the player
 * @param	t_mlx	for fill the value of the player
 *
 * @return	return void
**/

void	ft_find_player_pos(char **tmp, t_mlx *mlx)
{
	int		pos[2];
	char	*s;
	char	**tmpb;

	tmpb = tmp;
	pos[1] = 0;
	while (tmp)
	{
		pos[0] = 0;
		s = *tmp;
		while (*s)
		{
			if (ft_is_player(*s, &mlx->player[ANGLE]))
			{
				*s = '0';
				ft_init_player(mlx, pos);
				return ;
			}
			pos[0]++;
			s++;
		}
		pos[1]++;
		tmp++;
	}
	tmp = tmpb;
}
