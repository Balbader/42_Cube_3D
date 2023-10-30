/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_line_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:15:05 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 16:15:07 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_line_type(char *str)
{
	int	type;

	type = 0;
	if (str[0] == '\0')
		type = EMPTY_LINE;
	else if (ft_is_cardinal_char(str[0]))
		type = TEXTURE_LINE;
	else if (ft_is_color_char(str[0]))
		type = COLOR_LINE;
	else if (str[0] == ' ' || str[0] == '0' || str[0] == '1')
		type = MAP_LINE;
	else
		type = ERROR_LINE;
	return (type);
}
