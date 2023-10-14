/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:59:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 15:59:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_nbrlen(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str))
	{
		i++;
		str++;
	}
	while (*str == ' ')
		str++;
	if (ft_isdigit(*str))
		return (-1);
	return (i);
}
