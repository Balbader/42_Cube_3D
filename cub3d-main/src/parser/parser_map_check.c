/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:40 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/10 12:46:16 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && is_nsew(c) == 0 && c != '\n')
		return (E_INVALID_CHAR);
	return (E_OK);
}

static int	first_char_test(char *line, int j)
{
	j = 0;
	if (line[0] == '\n')
		return (E_EMPTY_LINE);
	while (line[j] && line[j] == ' ')
		j++;
	if (valid_char(line[j]) != E_OK)
		return (ft_putstr_fd(ERR_INV_CHAR, 2), E_INVALID_CHAR);
	else if (line[j] != '1' && line[j] != '\n')
		return (ft_putstr_fd(ERR_OPEN_MAP, 2), E_OPEN_MAP);
	return (E_OK);
}

int	parser_map_check_core(char **grid, int j, int *i, int *perso)
{
	*i = 0;
	while (grid[++(*i)] && grid[(*i) + 1])
	{
		j = 0;
		if (first_char_test(grid[(*i)], j) != E_OK)
			return (first_char_test(grid[(*i)], j));
		while (grid[(*i)][++j] != '\n' && grid[(*i)][j + 1] != '\n')
		{
			if (valid_char(grid[(*i)][j]) != E_OK)
				return (ft_putstr_fd(ERR_INV_CHAR, 2), E_INVALID_CHAR);
			if (is_nsew(grid[(*i)][j]) == 1 || grid[(*i)][j] == '0')
			{
				if (is_nsew(grid[(*i)][j]) == 1 && ++(*perso) > 1)
					return (ft_putstr_fd(ERR_SEV_CHAR, 2), E_SEVERAL_CHAR);
				if (parser_mapcheck_look_around(grid, *i, j) != E_OK)
					return (ft_putstr_fd(ERR_OPEN_MAP, 2), E_OPEN_MAP);
			}
		}
	}
	return (E_OK);
}

static void	init_variables(int *i, int *j, int *perso)
{
	*i = 0;
	*j = -1;
	*perso = 0;
}

int	parser_map_check(char **grid)
{
	int	i;
	int	j;
	int	perso;

	init_variables(&i, &j, &perso);
	while (grid[0][++j] != '\n')
	{
		if (valid_char(grid[0][j]) != E_OK)
			return (ft_putstr_fd(ERR_INV_CHAR, 2), E_INVALID_CHAR);
		else if (grid[0][j] != ' ' && grid[0][j] != '1' && grid[0][j] != '\n')
			return (ft_putstr_fd(ERR_OPEN_MAP, 2), E_OPEN_MAP);
	}
	if (parser_map_check_core(grid, j, &i, &perso) != E_OK)
		return (1);
	j = -1;
	while (grid[i][++j] && grid[i][j] != '\n')
	{
		if (valid_char(grid[i][j]) != E_OK)
			return (ft_putstr_fd(ERR_INV_CHAR, 2), E_INVALID_CHAR);
		if (grid[i][j] != ' ' && grid[i][j] != '1')
			return (ft_putstr_fd(ERR_OPEN_MAP, 2), E_OPEN_MAP);
	}
	if (perso == 0)
		return (ft_putstr_fd(ERR_NO_CHAR, 2), E_NO_CHAR);
	return (E_OK);
}
