/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_texture_and_addr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:00:30 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 14:00:32 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_xpm_texture_and_addr(void *mlx_ptr, char *txt_name, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, txt_name, &img->width,
			&img->height);
	if (!img->img)
		return (EXIT_FAILURE);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (EXIT_SUCCESS);
}
