/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:40:33 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:40:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_gnl_recursive(int fd, char **line, int index)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == -1)
		return (-1);
	if (ret == 1 && buf != '\n')
	{
		if (ft_gnl_recursive(fd, line, index + 1) == -1)
			return (-1);
		(*line)[index] = buf;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (!(*line))
			return (-1);
		(*line)[index] = '\0';
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = ft_gnl_recursive(fd, line, 0);
	if (!line || ret == -1)
		return (-1);
	return (ret);
}
