/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pressed_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:12:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:12:50 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_pressed_key(int key, t_world *world)
{
	if (key == KEY_ESC)
		ft_quit(world, SUCCESS);
	else if (key == KEY_A)
		world->ctrls.a = TRUE;
	else if (key == KEY_D)
		world->ctrls.d = TRUE;
	else if (key == KEY_W)
		world->ctrls.w = TRUE;
	else if (key == KEY_S)
		world->ctrls.s = TRUE;
	else if (key == KEY_LEFT)
		world->ctrls.left = TRUE;
	else if (key == KEY_RIGHT)
		world->ctrls.right = TRUE;
	return (TRUE);
}
