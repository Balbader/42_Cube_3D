/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:56:54 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 06:56:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_is_player(char c, double *angle)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			*angle = M_PI / 2;
		else if (c == 'S')
			*angle = 1.5 * M_PI;
		else if (c == 'E')
			*angle = M_PI;
		else if (c == 'W')
			*angle = 0;
		return (true);
	}
	return (false);
}
