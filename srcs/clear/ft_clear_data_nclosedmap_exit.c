/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data_nclosedmap_exit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:57:56 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 12:57:58 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_data_nclosedmap_exit(t_data **data, int i, char *msg)
{
	int	j;

	j = 0;
	write(2, "Error\n", 6);
	printf("%s", msg);
	while (j < (*data)->map_height)
	{
		if ((j == i - 1) && (i - 1 > 0))
			printf("[%d] " YELLOW "[%s]" RESET"\n", j, (*data)->map[i - 1]);
		else if (j == i)
			printf("[%d] " RED "[%s]" RESET"\n", j, (*data)->map[i]);
		else if ((j == i + 1) && (i + 1 < (*data)->map_height))
			printf("[%d] " YELLOW "[%s]" RESET"\n", j, (*data)->map[i + 1]);
		else
			printf("[%d] [%s]\n", j, (*data)->map[j]);
		j++;
	}
	ft_clear_data(data);
	exit(EXIT_FAILURE);
}
