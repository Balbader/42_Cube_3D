/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_trim_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:19:05 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 16:19:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_sub_trim_str(char *str, char *set)
{
	int		len;
	char	*substr;

	len = 0;
	substr = NULL;
	if (!str || !set)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len - 1]))
		len--;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (len--)
		substr[len] = str[len];
	return (substr);
}
