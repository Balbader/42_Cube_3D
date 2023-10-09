/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:45:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/09 10:45:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_remove_spaces(char *str)
{
	int		i;
	int		nb_spaces;
	char	*new_str;

	nb_spaces = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= ' ')
			nb_spaces++;
		i++;
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - nb_spaces + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str > ' ')
			new_str[i++] = *str;
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}
