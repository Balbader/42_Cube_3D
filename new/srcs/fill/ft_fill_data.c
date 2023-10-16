/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:04:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:04:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_data(t_data **data, t_list **list)
{
	ft_init_data(data, list);
	ft_fill_texture(data, list, &(*data)->north_texture, "NO ");
	ft_fill_texture(data, list, &(*data)->south_texture, "SO ");
	ft_fill_texture(data, list, &(*data)->west_texture, "WE ");
	ft_fill_texture(data, list, &(*data)->east_texture, "EA ");
	ft_fill_rgb(data, list, &(*data)->floor_rgb, "F ");
	ft_fill_rgb(data, list, &(*data)->ceiling_rgb, "C ");
	ft_get_map_size(data, list);
	ft_init_map(data, list);
	ft_fill_map(data, list);
	ft_get_player_info(data);
}
