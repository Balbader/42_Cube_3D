/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:02:52 by eloevenb          #+#    #+#             */
/*   Updated: 2023/03/04 08:08:25 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = 0;
	dest = NULL;
	i = 0;
	while (s[(int) len] && len < n)
		len++;
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[(int) i] = s[(int) i];
		i++;
	}
	dest[(int) len] = '\0';
	return (dest);
}
