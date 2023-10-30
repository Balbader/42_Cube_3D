/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures_extensions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:49:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:49:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_textures_extensions(t_data **data)
{
	if (ft_check_extension((*data)->north_texture, ".xpm"))
		ft_clear_data_exit(data, WNOEXT);
	else if (ft_check_extension((*data)->south_texture, ".xpm"))
		ft_clear_data_exit(data, WSOEXT);
	else if (ft_check_extension((*data)->west_texture, ".xpm"))
		ft_clear_data_exit(data, WWEEXT);
	else if (ft_check_extension((*data)->east_texture, ".xpm"))
		ft_clear_data_exit(data, WEAEXT);
}
