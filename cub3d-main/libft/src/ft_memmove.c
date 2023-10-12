/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:43:49 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:27 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *) dest;
	src_ptr = (const char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (dest_ptr < src_ptr)
			dest_ptr[i] = src_ptr[i];
		else
			dest_ptr[n - i - 1] = src_ptr[n - i - 1];
		i++;
	}
	return (dest);
}
