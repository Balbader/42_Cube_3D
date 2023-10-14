/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_duplicates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:37:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:37:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_list_duplicates(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		dup[6];

	tmp = *list;
	i = 0;
	ft_bzero_int_tab(dup, 6, 0);
	while (tmp)
	{
		if (tmp->type == 2)
			ft_check_cardinal_duplicates(list, dup, tmp->line, i);
		if (tmp->type == 3)
			ft_check_color_duplicates(list, dup, tmp->line, i);
		i++;
		tmp = tmp->next;
	}
	ft_check_missing_lines(list, dup);
}
