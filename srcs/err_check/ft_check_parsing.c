/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:50:51 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 15:50:53 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_parsing(t_world *world, char *msg, int line)
{
	char	c;

	if (world->error)
		return ;
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	if (line > 0)
	{
		write(1, " on line ", 9);
		c = line / 10 + '0';
		if (c != '0')
			write(1, &c, 1);
		c = line % 10 + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	world->error = TRUE;
}
