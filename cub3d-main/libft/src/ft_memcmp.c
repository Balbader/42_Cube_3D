/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:36:31 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:20 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *) s2)[i] == ((unsigned char *) s1)[i])
		i++;
	if (i < n)
		return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
	return (0);
}
