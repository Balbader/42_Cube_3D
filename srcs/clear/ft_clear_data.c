/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:54:56 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 12:54:58 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_data(t_data **data)
{
	if (!*data)
		return ;
	if ((*data)->map)
		ft_free_array((*data)->map);
	free((*data)->north_texture);
	free((*data)->south_texture);
	free((*data)->west_texture);
	free((*data)->east_texture);
	free(*data);
}
