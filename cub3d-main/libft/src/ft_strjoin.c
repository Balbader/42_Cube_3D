/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:20:19 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:59 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*dst;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		dst[i] = s2[i - len_s1];
		i++;
	}
	dst[len_s1 + len_s2] = '\0';
	return (dst);
}
