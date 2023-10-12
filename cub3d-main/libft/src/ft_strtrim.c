/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:24:48 by eloevenb          #+#    #+#             */
/*   Updated: 2023/04/05 14:06:50 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_find(char const *set, char c)
{
	while (*set && c != *set)
		set++;
	if (c == *set)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*trimmed;

	if (!s1 || !set)
		return (NULL);
	end = (unsigned int) ft_strlen(s1);
	start = 0;
	while (start < end && ft_find(set, s1[start]))
		start++;
	while (end > start && ft_find(set, s1[end - 1]))
		end--;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
