/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:53:08 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 13:53:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char *str, int start, int len)
{
	int		size;
	char	*substr;
	int		i;

	size = (start + len > ft_strlen(str)) ? ft_strlen(str) - start : len;
	if (!(substr = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
