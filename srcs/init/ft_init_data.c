/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:00:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/30 13:00:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_data **data, t_list **list)
{
	*data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!*data)
		ft_clear_all_exit(data, list, DATAFAIL);
	(*data)->map_height = 0;
	(*data)->map_width = 0;
	(*data)->map = NULL;
	(*data)->north_texture = NULL;
	(*data)->south_texture = NULL;
	(*data)->west_texture = NULL;
	(*data)->east_texture = NULL;
	(*data)->floor_rgb = 0;
	(*data)->ceiling_rgb = 0;
	(*data)->player_x = 0;
	(*data)->player_y = 0;
	(*data)->player_dir = '\0';
	(*data)->player_dir_radian = 0.0;
}
