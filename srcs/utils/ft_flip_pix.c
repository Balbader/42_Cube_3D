/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flip_pix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:33:33 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:33:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_flip_pix(t_world *world)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < world->scr_width)
	{
		j = 0;
		while (j < world->scr_height / 2)
		{
			tmp = ft_get_screen_pixel(world->screen, i, j);
			ft_set_screen_pixel(world->screen, i, j,
				ft_get_screen_pixel(world->screen, i,
					world->scr_height - j - 1));
			ft_set_screen_pixel(world->screen, i,
					world->scr_height - j - 1, tmp);
			j++;
		}
		i++;
	}
}
