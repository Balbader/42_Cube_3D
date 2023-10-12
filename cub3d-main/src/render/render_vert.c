/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_vert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:22:26 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/08 12:09:55 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->size_line) + (x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	get_pixel_color(t_img *texture, double text_x, double text_y)
{
	int				offset;
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	offset = (int) text_y * texture->size_line + (int) text_x * \
	(texture->bpp / 8);
	b = texture->addr[offset];
	g = texture->addr[offset + 1];
	r = texture->addr[offset + 2];
	return ((r << 16) + (g << 8) + b);
}

int	get_rgb_color(t_rgb *color)
{
	return ((color->r << 16) + (color->g << 8) + color->b);
}

static void	data_init(t_dda_output *ddoutput, t_game_data *game_data, \
double *data, t_vector2d *wall)
{
	ddoutput->text_x *= game_data->texture_to_render->width;
	data[0] = 1.0 * game_data->texture_to_render->height / \
	(game_data->window.height / ddoutput->dist);
	data[1] = (wall->x - game_data->window.height / 2 + \
	(game_data->window.height / ddoutput->dist) / 2) * data[0];
}

// data -0 step;
// data -1 text_start;
// data -2 index
void	render_vert(t_game_data *game_data, int x, t_vector2d *wall, \
t_dda_output *ddoutput)
{
	double	data[3];

	data_init(ddoutput, game_data, data, wall);
	data[2] = 0;
	while (data[2] < game_data->window.height)
	{
		if (data[2] < wall->x)
			img_pixel_put(&(game_data->img), x, data[2], \
			get_rgb_color(&(game_data->ceiling_color)));
		else if (data[2] < wall->y)
		{
			if (data[1] >= game_data->texture_to_render->height)
				ddoutput->text_y = game_data->texture_to_render->height - 1;
			else
				ddoutput->text_y = data[1];
			data[1] += data[0];
			img_pixel_put(&(game_data->img), x, data[2], \
			get_pixel_color(game_data->texture_to_render, \
			ddoutput->text_x, ddoutput->text_y));
		}
		else
			img_pixel_put(&(game_data->img), x, data[2], \
			get_rgb_color(&(game_data->floor_color)));
		data[2]++;
	}
}
