/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:59:20 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/05 10:59:22 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_game_loop(t_world *world)
{
	t_bool	should_draw;

	should_draw = ft_move(world);
	should_draw = ft_rotate(world) || should_draw;
	if (should_draw)
		ft_draw(world);
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_world	*world;

	world = ft_init_world(ac, av);
	if (!world)
		return (ERROR);
	ft_draw(world);
	if (!world->save)
	{
		mlx_hook(world->mlx.win, 2, 1L << 0, ft_pressed_key, world);
		mlx_hook(world->mlx.win, 3, 1L << 1, ft_released_key, world);
		mlx_hook(world->mlx.win, 17, 0, ft_quit, world);
		mlx_loop_hook(world->mlx.ptr, ft_game_loop, world);
		mlx_loop(world->mlx.ptr);
	}
	ft_quit(world, SUCCESS);
	return (0);
}
