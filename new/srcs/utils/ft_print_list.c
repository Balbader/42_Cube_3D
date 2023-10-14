/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:48:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 15:48:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_list(t_list *list)
{
	int	i;

	i = 0;
	printf("Linked list of map file:\n");
	while (list)
	{
		printf("[%3d] [len = %3d] [type = %d] " GREEN "[" RESET "%s" GREEN "]" \
			RESET "\n", i, list->line_size, list->type, list->line);
		i++;
		list = list->next;
	}
	printf("\n");
}
