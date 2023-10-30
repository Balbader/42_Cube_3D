/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_trgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:02:32 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 16:02:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Create a trgb single int from 4 int. One byte containing 2^8 = 256
 * values, and RGB range is [0-255], we fit each color in a byte, because an
 * int is 4 bytes
 *
 * @param t transparency
 * @param r red
 * @param g green
 * @param b blie
 * @return int
**/
int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
