/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_check_alt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:38:49 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/08 10:40:05 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty_texture(char *line)
{
	while (*line && *line == ' ')
		line++;
	if (*line && *line != '\n')
		return (0);
	return (1);
}

int	get_texture_id(char *line)
{
	int	id;

	id = -2;
	if (line[0] == 'N' && line[1] == 'O' && !is_empty_texture(line + 2))
		id = 0;
	else if (line[0] == 'S' && line[1] == 'O' && !is_empty_texture(line + 2))
		id = 1;
	else if (line[0] == 'E' && line[1] == 'A' && !is_empty_texture(line + 2))
		id = 2;
	else if (line[0] == 'W' && line[1] == 'E' && !is_empty_texture(line + 2))
		id = 3;
	else if (line[0] == 'F' && line[1] == ' ')
		id = 4;
	else if (line[0] == 'C' && line[1] == ' ')
		id = 5;
	else if (line[0] == '\n')
		id = -1;
	return (id);
}
