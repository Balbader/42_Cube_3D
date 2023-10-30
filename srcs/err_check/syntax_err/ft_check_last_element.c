/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_last_element.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:55:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:55:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_last_element(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (ft_is_map_str(tmp->line))
		ft_clear_list_syntax_exit(list, i, tmp->line, ENDFILE);
}
