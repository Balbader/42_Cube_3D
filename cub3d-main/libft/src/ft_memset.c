/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:24:34 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:30 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s_ptr;

	s_ptr = (char *) s;
	i = 0;
	while (i < n)
	{
		s_ptr[i] = c;
		i++;
	}
	return (s);
}
