/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_to_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:30:32 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:30:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_nb_to_mem(char *dst, int nb, int nb_bytes)
{
	int		shift;
	int		i;

	i = nb_bytes - 1;
	shift = (nb_bytes > 1) ? (nb_bytes - 1) * 8 : 0;
	while (shift > 0)
	{
		dst[i] = (nb >> shift) & 0xFF;
		shift -= 8;
		i--;
	}
	dst[i] = nb & 0xFF;
}
