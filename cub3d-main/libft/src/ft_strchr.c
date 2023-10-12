/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:26:47 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:51 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && (unsigned char) s[i] != (unsigned char) c)
		i++;
	if ((unsigned char) s[i] == (unsigned char) c)
		return (((char *) s) + i);
	return (NULL);
}
