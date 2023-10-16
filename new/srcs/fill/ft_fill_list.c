/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:43:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:43:20 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_list(int fd, t_list **list)
{
	char	*line;
	t_list	*elem;
	int		ret;

	line = NULL;
	elem = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		elem = ft_lst_create(line);
		if (!elem)
			ft_clear_list_free_line_exit(list, line);
		*list = ft_lstaddback(list, elem);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
	{
		if (line[0] != '\0')
			*list = ft_lstaddback(list, elem);
		free(line);
	}
	else
		ft_clear_list_free_line_exit(list, line);
}
