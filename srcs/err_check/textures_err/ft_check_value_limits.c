/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_value_limits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:58:28 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:58:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_value_limits(t_data **data, t_list **list, \
			char **array, char **str)
{
	int	i;
	int	len;
	int	nbr;

	i = 0;
	len = 0;
	nbr = 0;
	while (array && array[i])
	{
		len = 0;
		len = ft_nbrlen(array[i]);
		nbr = ft_atoi(array[i]);
		if (len == -1 || len > 3 || nbr > 255)
		{
			free(*str);
			ft_free_array(array);
			if (len == -1)
				ft_clear_all_exit(data, list, SYNTAXRGB);
			if (len > 3)
				ft_clear_all_exit(data, list, BIGRGB);
			if (nbr > 255)
				ft_clear_all_exit(data, list, BIGRGB);
		}
		i++;
	}
}
