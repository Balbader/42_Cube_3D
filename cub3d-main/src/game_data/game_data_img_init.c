/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_img_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:47:12 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/10 13:19:54 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_imgs(t_game_data *data)
{
	if (!data->s_texture.mlx_img)
		return (ft_putstr_fd("Error\nSouth texture not found\n", 2), 1);
	if (!data->w_texture.mlx_img)
		return (ft_putstr_fd("Error\nWest texture not found\n", 2), 1);
	if (!data->e_texture.mlx_img)
		return (ft_putstr_fd("Error\nEast texture not found\n", 2), 1);
	if (!data->n_texture.mlx_img)
		return (ft_putstr_fd("Error\nNorth texture not found\n", 2), 1);
	return (E_OK);
}

int	img_init(t_game_data *d)
{
	d->img.mlx_img = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->img.addr = mlx_get_data_addr(d->img.mlx_img, &(d->img.bpp), \
	&(d->img.size_line), &(d->img.endian));
	d->n_texture.mlx_img = mlx_xpm_file_to_image(d->mlx, \
	d->north_texture, &d->n_texture.width, &d->n_texture.height);
	d->s_texture.mlx_img = mlx_xpm_file_to_image(d->mlx, \
	d->south_texture, &d->s_texture.width, &d->s_texture.height);
	d->e_texture.mlx_img = mlx_xpm_file_to_image(d->mlx, \
	d->east_texture, &d->e_texture.width, &d->e_texture.height);
	d->w_texture.mlx_img = mlx_xpm_file_to_image(d->mlx, \
	d->west_texture, &d->w_texture.width, &d->w_texture.height);
	if (check_imgs(d))
		return (game_exit(d), game_data_destroy(d), 1);
	d->n_texture.addr = mlx_get_data_addr(d->n_texture.mlx_img, \
	&(d->n_texture.bpp), &(d->n_texture.size_line), &(d->n_texture.endian));
	d->s_texture.addr = mlx_get_data_addr(d->s_texture.mlx_img, \
	&(d->s_texture.bpp), &(d->s_texture.size_line), &(d->s_texture.endian));
	d->e_texture.addr = mlx_get_data_addr(d->e_texture.mlx_img, \
	&(d->e_texture.bpp), &(d->e_texture.size_line), &(d->e_texture.endian));
	d->w_texture.addr = mlx_get_data_addr(d->w_texture.mlx_img, \
	&(d->w_texture.bpp), &(d->w_texture.size_line), &(d->w_texture.endian));
	return (0);
}
