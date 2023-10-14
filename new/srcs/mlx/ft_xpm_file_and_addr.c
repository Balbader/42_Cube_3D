/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_file_and_addr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:08:36 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 14:08:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_xpm_file_and_addr(void *mlx_ptr, t_img *img)
{
	size_t	i;

	i = 0;
	img->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (!img->img)
		return (EXIT_FAILURE);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = WIDTH;
	img->height = HEIGHT;
	return (EXIT_SUCCESS);
}
