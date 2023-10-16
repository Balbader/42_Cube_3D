/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:39:45 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 09:40:12 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(int count, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)malloc(sizeof(unsigned char) * (count * size));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
		*(ptr + i++) = 0;
	return ((void *)ptr);
}
