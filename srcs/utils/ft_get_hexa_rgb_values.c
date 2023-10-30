/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hexa_rgb_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:55:58 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:56:01 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int ft_check_rgb_format(char *str)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		++i;
	str += i;
	if (ft_strchr(str, ' ') != 0)
		return (1);
	return (0);
}

int	ft_get_hexa_rgb_values(t_data **data, t_list **list, char **str)
{
	char	**array;
	int		rgb[3];
	int		hexa_color;

	if (ft_check_rgb_format(*str) == 1)
	{
		printf("Shit is going down right here!\n");
		return (-1);
	}
	ft_bzero_int_tab(rgb, 3, 0);
	hexa_color = 0;
	array = ft_split(data, list, *str, ',');
	if (!array)
	{
		free(str);
		ft_clear_all_exit(data, list, COMASFAIL);
	}
	ft_check_value_limits(data, list, array, str);
	rgb[RED_RGB] = ft_atoi(array[RED_RGB]);
	rgb[GREEN_RGB] = ft_atoi(array[GREEN_RGB]);
	rgb[BLUE_RGB] = ft_atoi(array[BLUE_RGB]);
	hexa_color = ft_create_trgb(0, rgb[RED_RGB], rgb[GREEN_RGB], rgb[BLUE_RGB]);
	ft_free_array(array);
	return (hexa_color);
}
