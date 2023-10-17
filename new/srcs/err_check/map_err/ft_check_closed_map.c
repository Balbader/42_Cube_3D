/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_closed_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:00:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:00:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_closed_map(t_data **data)
{
	if (ft_is_not_only_one_or_space_str((*data)->map[0]))
		ft_clear_data_nclosedmap_exit(data, 0, NCLOSEDMAP);
	if (ft_is_not_only_one_or_space_str((*data)->map[(*data)->map_height - 1]))
		ft_clear_data_nclosedmap_exit(data, ((*data)->map_height - 1), \
			NCLOSEDMAP);
	ft_check_first_last_char(data);
	ft_check_inner_map(data);
}
