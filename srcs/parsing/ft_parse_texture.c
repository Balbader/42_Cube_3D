/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:48:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:48:19 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_texture(t_world *world, char *ptr, int id, int line_nb)
{
	t_img	*texture;

	if (id == 4 && world->texture_sprite.filename)
		ft_check_parsing(world, "Sprite texture was already defined", line_nb);
	else if (id < 4 && world->textures[id].filename)
		ft_check_parsing(world, "Wall texture was already defined", line_nb);
	else
	{
		texture = (id < 4) ? &(world->textures[id]) : &(world->texture_sprite);
		while (*ptr <= ' ')
			ptr++;
		texture->filename = ft_strdup(ft_trim(ptr));
		if (open(texture->filename, O_RDONLY) < 0)
			ft_check_parsing(world, "Texture filename is invalid", 0);
	}
}
