/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:45:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 15:45:14 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_data(t_data *data)
{
	printf("Game Infos:\n");
	printf("North texture path : %s\n", data->north_texture);
	printf("South texture path : %s\n", data->south_texture);
	printf("West texture path  : %s\n", data->west_texture);
	printf("East texture path  : %s\n", data->east_texture);
	printf("Floor RGB color    : %d\n", data->floor_rgb);
	printf("Ceiling RGB color  : %d\n", data->ceiling_rgb);
	printf("Player x position  : %d\n", data->player_x);
	printf("Player y position  : %d\n", data->player_y);
	printf("Player direction   : %c\n", data->player_dir);
	printf("Player dir radian  : %f\n\n", data->player_dir_radian);
}
