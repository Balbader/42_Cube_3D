/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:20:11 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:26:25 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture(t_game_data *game_data, char *line)
{
	int		i;
	char	*dst;

	i = 0;
	if (ft_strlen(line) < 3)
		return (1);
	while (line[i + 2] == ' ')
		i++;
	dst = ft_strdup(line + i + 2);
	if (!dst)
		return (1);
	dst[ft_strlen(dst) - 1] = '\0';
	if (!game_data->north_texture && ft_strncmp(line, "NO", 2) == 0)
		game_data->north_texture = dst;
	else if (!game_data->south_texture && ft_strncmp(line, "SO", 2) == 0)
		game_data->south_texture = dst;
	else if (!game_data->east_texture && ft_strncmp(line, "EA", 2) == 0)
		game_data->east_texture = dst;
	else if (!game_data->west_texture && ft_strncmp(line, "WE", 2) == 0)
		game_data->west_texture = dst;
	else
		return (free(dst), 1);
	return (0);
}

static int	get_color(t_game_data *game_data, char *line)
{
	int		i;
	char	**rgb;
	t_rgb	*color;

	i = 0;
	color = NULL;
	while (line[i + 1] == ' ')
		i++;
	rgb = ft_split(line + i + 1, ',');
	if (!rgb)
		return (1);
	if (line[0] == 'F')
		color = &(game_data->floor_color);
	else if (line[0] == 'C')
		color = &(game_data->ceiling_color);
	if (!(rgb[0] && rgb[1] && rgb[2] && color))
		return (1);
	color->r = (unsigned char) ft_atoi(rgb[0]);
	color->g = (unsigned char) ft_atoi(rgb[1]);
	color->b = (unsigned char) ft_atoi(rgb[2]);
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	return (free(rgb), 0);
}

static void	get_map_grid(t_game_data *game_data, int map_fd, char *line)
{
	int	y;

	game_data->map.grid = (char **) malloc((game_data->map.height + 1) \
	* sizeof(char *));
	if (!game_data->map.grid)
		return ;
	game_data->map.width = 0;
	y = 0;
	while (line && line[0] != '\n')
	{
		game_data->map.grid[y] = ft_strdup(line);
		if (!game_data->map.grid[y])
			break ;
		if ((int) ft_strlen(game_data->map.grid[y]) > game_data->map.width)
			game_data->map.width = ft_strlen(game_data->map.grid[y]);
		y++;
		free(line);
		line = get_next_line(map_fd);
	}
	game_data->map.grid[y] = NULL;
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
	}
}

static int	is_map_begin(char *line)
{
	if (!line || line[0] == '\n')
		return (0);
	if (line[0] != ' ' && line[0] != '1')
		return (0);
	return (1);
}

int	parser_get_map(t_game_data *g_d, char *map_path)
{
	int		map_fd;
	char	*line;
	int		e;

	e = E_OK;
	if (parser_error_check(g_d, map_path))
		return (E_SYNTAX_ERROR);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (ft_putstr_fd("Error\n", 2), perror(map_path), E_FILE);
	line = get_next_line(map_fd);
	while (line && !is_map_begin(line))
	{
		if (is_nsew(line[0]) == 1)
		{	
			if (get_texture(g_d, line) == 1)
				e = E_DUPLICATE_TEXTURE;
		}
		else if (line[0] == 'F' || line[0] == 'C')
			if (get_color(g_d, line) == 1)
				e = E_SYNTAX_ERROR;
		free(line);
		line = get_next_line(map_fd);
	}
	return (get_map_grid(g_d, map_fd, line), close(map_fd), put_error(e));
}
