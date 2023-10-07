/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_released_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:14:05 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:14:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_released_key(int key, t_world *world)
{
	if (key == KEY_A)
		world->ctrls.a = FALSE;
	else if (key == KEY_D)
		world->ctrls.d = FALSE;
	else if (key == KEY_W)
		world->ctrls.w = FALSE;
	else if (key == KEY_S)
		world->ctrls.s = FALSE;
	else if (key == KEY_LEFT)
		world->ctrls.left = FALSE;
	else if (key == KEY_RIGHT)
		world->ctrls.right = FALSE;
	return (TRUE);
}
