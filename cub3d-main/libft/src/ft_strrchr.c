/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:29:08 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:17 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0 && (unsigned char) s[i] != (unsigned char) c)
		i--;
	if ((unsigned char) s[i] == (unsigned char) c)
		return (((char *) s) + i);
	return (NULL);
}
