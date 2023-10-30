/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data_syntax_exit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:00:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 13:00:51 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_data_syntax_exit(t_data **data, int i, char *line, char *msg)
{
	write(2, "Error\n", 6);
	printf("%s", msg);
	printf("[%d] " YELLOW "[%s]" RESET"\n", i, line);
	ft_clear_data(data);
	exit(EXIT_FAILURE);
}
