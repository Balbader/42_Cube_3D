/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_alt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:34:31 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/08 11:35:22 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

static void	init_side_dist(t_game_data *game_data, t_vector2d *ray, \
t_vector2d *side_dist, t_vector2d *delta_dist)
{
	int	coord_x;
	int	coord_y;

	coord_x = floor(game_data->player.coords.x);
	coord_y = floor(game_data->player.coords.y);
	if (ray->x < 0)
		side_dist->x = (game_data->player.coords.x - coord_x) * delta_dist->x;
	else
		side_dist->x = (coord_x + 1.0 - game_data->player.coords.x) * \
		delta_dist->x;
	if (ray->y < 0)
		side_dist->y = (game_data->player.coords.y - coord_y) * delta_dist->y;
	else
		side_dist->y = (coord_y + 1.0 - game_data->player.coords.y) * \
		delta_dist->y;
}

static void	init_step(t_vector2d *step, t_vector2d *ray)
{
	if (ray->x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (ray->y < 0)
		step->y = -1;
	else
		step->y = 1;
}

static void	init_delta_dist(t_vector2d *delta_dist, t_vector2d *ray)
{
	if (ray->x == 0)
		delta_dist->x = DBL_MAX;
	else
		delta_dist->x = fabs(1.0 / ray->x);
	if (ray->y == 0)
		delta_dist->y = DBL_MAX;
	else
		delta_dist->y = fabs(1.0 / ray->y);
}

static void	settings(t_vector2d	*data, t_dda_output *ddoutput, \
t_game_data *game_data)
{
	int			hit;

	hit = 0;
	while (!hit)
	{
		if (data[0].x < data[0].y)
		{
			data[0].x += data[1].x;
			data[3].x += data[2].x;
			ddoutput->side = 0;
		}
		else
		{
			data[0].y += data[1].y;
			data[3].y += data[2].y;
			ddoutput->side = 1;
		}
		if (map_out_of_bounds(game_data, data[3].x, data[3].y))
			hit = 1;
	}
}

// data 0side_dist;
// data 1 delta_dist;
// data 2 step;
// data 3 pos;

void	dda_get_dist(t_game_data *game_data, t_vector2d *ray, \
t_dda_output *ddoutput)
{
	t_vector2d	data[4];

	init_delta_dist(&data[1], ray);
	init_side_dist(game_data, ray, &data[0], &data[1]);
	init_step(&data[2], ray);
	data[3].x = game_data->player.coords.x;
	data[3].y = game_data->player.coords.y;
	settings(data, ddoutput, game_data);
	if (ddoutput->side == 0)
	{
		ddoutput->dist = data[0].x - data[1].x;
		ddoutput->text_x = data[3].y + ddoutput->dist * ray->y;
	}
	else
	{
		ddoutput->dist = data[0].y - data[1].y;
		ddoutput->text_x = data[3].x + ddoutput->dist * ray->x;
	}
	ddoutput->text_x -= floor(ddoutput->text_x);
}
