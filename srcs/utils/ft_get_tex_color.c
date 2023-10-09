/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tex_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:40:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:40:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_tex_color(t_img tex, double u, double v)
{
	char			*ptr;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	ptr = tex.data + (int)(v * tex.height) * tex.size_line
		+ (int)(u * tex.width) * (tex.bpp >> 3);
	r = (unsigned char)(tex.endian ? *ptr : *(ptr + 2));
	g = (unsigned char)(*(ptr + 1));
	b = (unsigned char)(tex.endian ? *(ptr + 2) : *ptr);
	return ((r << 16) + (g << 8) + b);
}
