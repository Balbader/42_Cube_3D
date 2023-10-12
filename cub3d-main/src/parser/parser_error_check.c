/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:18:01 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:24:54 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_begin(char *line)
{
	if (!line || line[0] == '\n')
		return (0);
	if (line[0] != ' ' && line[0] != '1')
		return (0);
	return (1);
}

static void	init_textures(int textures[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		textures[i] = 0;
		i++;
	}
}

static int	has_all_textures(int textures[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!textures[i])
			return (0);
		i++;
	}
	return (1);
}

static int	map_filling(t_game_data *game_data, int map_fd, char *line)
{
	game_data->map.height = 0;
	while (line && (line[0] == '1' || line[0] == ' '))
	{
		game_data->map.height++;
		free(line);
		line = get_next_line(map_fd);
	}
	while (line)
	{
		if (line[0] != '\n')
		{
			while (line)
			{
				free(line);
				line = get_next_line(map_fd);
			}
			close(map_fd);
			return (E_SEVERAL_MAPS);
		}
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	return (E_OK);
}

	//data 0-map_fd
	//data 1-texture_id
	//data 2-error

int	parser_error_check(t_game_data *game_data, char *map_path)
{
	int		textures[6];
	char	*line;
	int		data[3];

	data[0] = open(map_path, O_RDONLY);
	if (data[0] < 0)
		return (put_map_error(map_path), 1);
	data[2] = 0;
	init_textures(textures);
	line = get_next_line(data[0]);
	while (line && !is_map_begin(line))
	{
		data[1] = get_texture_id(line);
		if (data[1] >= 0)
			textures[data[1]] = 1;
		else if (data[1] == -2)
			data[2] = E_INVALID_LINE;
		free(line);
		line = get_next_line(data[0]);
	}
	if (map_filling(game_data, data[0], line) == E_SEVERAL_MAPS)
		return (ft_fprintf(2, "Error\nSeveral maps\n"), E_SEVERAL_MAPS);
	if (!has_all_textures(textures))
		return (ft_fprintf(2, "Error\nMissing texture\n"), E_MISSING_TEXTURE);
	return (data[2]);
}
