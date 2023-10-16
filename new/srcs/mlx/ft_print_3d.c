/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:31:16 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 14:31:17 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef void		(*t_fct)(
	t_img *const img[2],
	t_rayon const *const rayon,
	float i[4]);

static t_fct const	g_fct[] = {
	ft_print_nord,
	ft_print_south,
	ft_print_west,
	ft_print_east
};

void	ft_fill_floor_wall_and_ceiling(t_mlx *const mlx, \
		t_rayon const *const rayon, float const line_h, int const x)
{
	const float	ceil_h;
	float		i;

	ceil_h = (HEIGHT - line_h) / 2;
	i = 0;
	while (i < ceil_h)
	{
		mlx->pict[IMAGE].addr[x + (int)i * WIDTH] = mlx->data->ceiling_rgb;
		i++;
	}
	g_fct[rayon->type]((t_img *[]){&mlx->pict[IMAGE], &mlx->pict[rayon->type]},
			rayon, (float []){x, i, lineh, ceil_h});
	i = lineh + ceil_h;
	while (i < HEIGHT)
	{
		mlx->pict[IMAGE].addr[x + (int)i * WIDTH] = mlx->data->floor_rgb;
		i++;
	}
}

void	ft_print_3d(t_mlx *const mlx, t_rayon *const rayon, double ra, int *x)
{
	double	ca;
	float	lineh;
	double	opposite;

	ca = mlx->player[ANGLE] - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	rayon->dist = rayon->dist * cos(ca);
	opposite = 2 * 0.57735026919 * rayon->dist;
	if (opposite <= 0)
		opposite = 0.1;
	lineh = 64 * HEIGHT / opposite;
	fill_floor_wall_and_ceiling(mlx, rayon, lineh, *x);
	*x += 1;
}
