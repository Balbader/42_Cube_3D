/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:47:37 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:47:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 3) == 0)
		{
			*dest = ft_sub_trim_str(tmp->line, src);
			if (!*dest && (ft_strcmp(src, "NO ") == 0))
				ft_clear_all_exit(data, list, NORTHFAIL);
			else if (!*dest && (ft_strcmp(src, "SO ") == 0))
				ft_clear_all_exit(data, list, SOUTHFAIL);
			else if (!*dest && (ft_strcmp(src, "WE ") == 0))
				ft_clear_all_exit(data, list, WESTFAIL);
			else if (!*dest && (ft_strcmp(src, "EA ") == 0))
				ft_clear_all_exit(data, list, EASTFAIL);
		}
		tmp = tmp->next;
	}
}
