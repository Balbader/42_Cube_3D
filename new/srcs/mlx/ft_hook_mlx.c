/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:45:04 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 14:45:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef X
# undef X
#endif

#ifdef Y
# undef Y
#endif

#define X 0
#define Y 1

static void	ft_check_player_and_move(t_mlx *mlx, char move, double new_pos[2])
{
	double	dist[2];

	dist[X] = cos(mlx->player[ANGLE]) * 5;
	dist[Y] = sin(mlx->player[ANGLE]) * 5;
	if (move == 'H')
		new_pos[X] = ((new_pos[Y] = mlx->player[Y_POS] - (0.005f * dist[Y]),
					mlx->player[X_POS] - (0.005f * dist[X])));
	else if (move == 'B')
		new_pos[X] = ((new_pos[Y] = mlx->player[Y_POS] + (0.005f * dist[Y]),
					mlx->player[X_POS] + (0.005f * dist[X])));
	else if (move == 'G')
		new_pos[X] = ((new_pos[Y] = mlx->player[Y_POS] + (0.005f * dist[X]),
					mlx->player[X_POS] - (0.005f * dist[Y])));
	else if (move == 'D')
		new_pos[X] = ((new_pos[Y] = mlx->player[Y_POS] - (0.005f * dist[X]),
					mlx->player[X_POS] + (0.005f * dist[Y])));
	if (new_pos[Y] == -1
		|| mlx->data->map[(int)new_pos[Y]][(int)new_pos[X]] == '1')
		return ;
	mlx->player[X_POS] = new_pos[X];
	mlx->player[Y_POS] = new_pos[Y];
	return ;
}

static void	ft_move_play(t_mlx *mlx, char move, double t[2])
{
	if (move == 'R' || move == 'L')
	{
		mlx->player[ANGLE] += *(double *)ft_ternary(move == 'R', &t[0], &t[1]);
		if (mlx->player[ANGLE] < 0)
			mlx->player[ANGLE] += 2 * M_PI;
		else if (mlx->player[ANGLE] > 2 * M_PI)
			mlx->player[ANGLE] -= 2 * M_PI;
		mlx->delta[0] = cos(mlx->player[ANGLE]) * 5;
		mlx->delta[1] = sin(mlx->player[ANGLE]) * 5;
		return ;
	}
	if (move == 'H')
		ft_check_player_and_move(mlx, 'H', (double [2]){-1, -1});
	else if (move == 'B')
		ft_check_player_and_move(mlx, 'B', (double [2]){-1, -1});
	else if (move == 'G')
		ft_check_player_and_move(mlx, 'G', (double [2]){-1, -1});
	else if (move == 'D')
		ft_check_player_and_move(mlx, 'D', (double [2]){-1, -1});
	mlx->player[X_PIXEL] = (mlx->player[X_POS] * 64);
	mlx->player[Y_PIXEL] = (mlx->player[Y_POS] * 64);
}

int	ft_key_hook(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_free_mlx(mlx);
		exit(0);
	}
	else if (key == D)
		ft_move_play(mlx, 'D', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == A)
		ft_move_play(mlx, 'G', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == S)
		ft_move_play(mlx, 'B', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == W)
		ft_move_play(mlx, 'H', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == LEFT)
		ft_move_play(mlx, 'L', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	else if (key == RIGHT)
		ft_move_play(mlx, 'R', (double [2]){2 * M_PI / 180, -(2 * M_PI / 180)});
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_print_min_map(mlx);
	return (0);
}

int	ft_close(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}
