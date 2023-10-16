/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:51:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 06:51:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
	@brief parse the map file. check the extension, open, syntax, dupplicates,
	values and fill data if correct to send to mlx

	@param argc main's argument count
	@param argv main's array of argument's strings
	@param data structure with all infos parsed in map file
	@return nothing
**/

void	ft_parsing(int ac, char **av, t_data **data)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	ft_check_argc(argc, argv);
	ft_check_open(argv[1], &fd);
	ft_fill_list(fd, &list);
	ft_check_list_syntax(&list);
	ft_check_list_duplicates(&list);
	ft_check_splitted_map(&list);
	ft_check_close(fd, list);
	ft_fill_data(data, &list);
	ft_ft_lst_clear(&list);
	ft_check_textures_extensions(data);
	ft_check_open_textures(data);
	ft_check_player_count(data);
	ft_check_closed_map(data);
	ft_print_data(*data);
}
