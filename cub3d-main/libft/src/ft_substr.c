/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:16:12 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:24 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	dst_len;
	size_t	i;
	char	*dst;

	dst_len = 0;
	i = 0;
	while (s[i] && i < start)
		i++;
	while (i >= start && s[start + dst_len] && dst_len < len)
		dst_len++;
	dst = (char *) malloc((dst_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < dst_len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[dst_len] = '\0';
	return (dst);
}
