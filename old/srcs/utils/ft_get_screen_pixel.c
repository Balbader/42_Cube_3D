/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_screen_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:39:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:39:45 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_screen_pixel(t_img screen, int i, int j)
{
	char			*ptr;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	ptr = screen.data + j * screen.size_line + i * (screen.bpp >> 3);
	r = (unsigned char)(screen.endian ? *ptr : *(ptr + 2));
	g = (unsigned char)(*(ptr + 1));
	b = (unsigned char)(screen.endian ? *(ptr + 2) : *ptr);
	return ((r << 16) + (g << 8) + b);
}
