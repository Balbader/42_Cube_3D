/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fc_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:56:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:56:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_fc_syntax(char *str)
{
	if ((ft_strncmp(str, "F ", 2) != 0) && (ft_strncmp(str, "C ", 2) != 0))
		return (EXIT_FAILURE);
	str++;
	while (*str)
	{
		if (!is_digit(*str) && *str != ' ' && *str != ',')
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}
