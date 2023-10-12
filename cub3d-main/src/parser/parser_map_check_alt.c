/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_check_alt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:09:32 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/07 13:13:59 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	strlen_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	parser_mapcheck_look_around(char **grid, int i, int j)
{
	int	previous_len;
	int	next_len;

	previous_len = strlen_newline(grid[i - 1]);
	next_len = strlen_newline(grid[i + 1]);
	if (i == 0 || j == 0 || !grid[i + 1] || grid[i][j + 1] == '\n')
		return (E_OPEN_MAP);
	if (j + 1 >= previous_len || j + 1 >= next_len)
		return (E_OPEN_MAP);
	if (grid[i][j + 1] == ' ' || grid[i][j -1] == ' ')
		return (E_OPEN_MAP);
	if (grid[i - 1][j + 1] == ' ' || grid[i - 1][j -1] == ' '
		|| grid[i - 1][j] == ' ')
		return (E_OPEN_MAP);
	if (grid[i + 1][j + 1] == ' ' || grid[i + 1][j -1] == ' '
		|| grid[i + 1][j] == ' ')
		return (E_OPEN_MAP);
	return (E_OK);
}
