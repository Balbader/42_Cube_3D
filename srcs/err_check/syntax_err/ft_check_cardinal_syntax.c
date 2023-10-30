/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cardinal_syntax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:57:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:57:03 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_cardinal_syntax(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0 \
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
