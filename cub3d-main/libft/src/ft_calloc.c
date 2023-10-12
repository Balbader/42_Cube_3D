/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:53:13 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:43:03 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((int) nmemb > INT_MAX / (int) size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i / size < nmemb)
	{
		((char *) mem)[(int) i] = '\0';
		i++;
	}
	return (mem);
}
