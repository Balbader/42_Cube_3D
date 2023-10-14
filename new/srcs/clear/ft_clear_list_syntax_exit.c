/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list_syntax_exit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:02:06 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:02:07 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_list_syntax_exit(t_list **list, int i, char *line, char *msg)
{
	write(2, "Error\n", 6);
	printf("%s", msg);
	printf("[%d] " YELLOW "[%s]" RESET"\n", i, line);
	ft_lst_clear(list);
	exit(EXIT_FAILURE);
}
