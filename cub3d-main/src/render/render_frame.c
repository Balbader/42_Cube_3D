/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:58:46 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/08 11:54:34 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

static void	wall_setting(t_vector2d	*wall, int line_height, \
t_game_data *game_data)
{
	wall->x = -line_height / 2 + game_data->window.height / 2;
	if (wall->x < 0)
		wall->x = 0;
	if (wall->x >= game_data->window.height)
		wall->x = game_data->window.height - 1;
	wall->y = line_height / 2 + game_data->window.height / 2;
	if (wall->y < 0)
		wall->y = 0;
	if (wall->y >= game_data->window.height)
		wall->y = game_data->window.height - 1;
}

static void	texture_to_render_settings(t_vector2d *ray, \
t_dda_output *ddoutput, t_game_data *game_data)
{
	if (ddoutput->side == 0)
	{
		if (ray->x > 0)
			game_data->texture_to_render = &(game_data->w_texture);
		else
			game_data->texture_to_render = &(game_data->e_texture);
	}
	else
	{
		if (ray->y > 0)
			game_data->texture_to_render = &(game_data->n_texture);
		else
			game_data->texture_to_render = &(game_data->s_texture);
	}
}

static void	draw_line(t_game_data *game_data, double x, t_vector2d *ray, \
t_dda_output *ddoutput)
{
	int			line_height;
	t_vector2d	wall;

	line_height = (int)(game_data->window.height / ddoutput->dist);
	wall_setting(&wall, line_height, game_data);
	texture_to_render_settings(ray, ddoutput, game_data);
	if (ddoutput->side == 0)
	{
		if (ray->x > 0)
			render_vert(game_data, x, &wall, ddoutput);
		else
			render_vert(game_data, x, &wall, ddoutput);
	}
	else
	{
		if (ray->y > 0)
			render_vert(game_data, x, &wall, ddoutput);
		else
			render_vert(game_data, x, &wall, ddoutput);
	}
}

int	render_frame(t_game_data *game_data)
{
	double			x;
	t_vector2d		camera;
	t_vector2d		ray;
	t_dda_output	ddoutput;

	x = 0;
	while (x < (double) game_data->window.width)
	{
		camera.x = 2 * x / (double) game_data->window.width - 1;
		ray.x = game_data->player.dir.x + game_data->player.plane.x * camera.x;
		ray.y = game_data->player.dir.y + game_data->player.plane.y * camera.x;
		dda_get_dist(game_data, &ray, &ddoutput);
		draw_line(game_data, x, &ray, &ddoutput);
		x++;
	}
	mlx_put_image_to_window(game_data->mlx, game_data->mlx_win, \
	game_data->img.mlx_img, 0, 0);
	return (0);
}
