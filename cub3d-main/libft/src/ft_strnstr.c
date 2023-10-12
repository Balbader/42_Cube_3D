/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:29 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:14 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	little_len = 0;
	while (little[little_len])
		little_len++;
	if (!little_len || little == big)
		return ((char *) big);
	i = 0;
	if ((!big && len <= 0) || (big && len < little_len))
		return (NULL);
	while (i <= len - little_len && big[i])
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j])
			j++;
		if (j == little_len)
			return (((char *) big) + i);
		i++;
	}
	return ((char *) NULL);
}
