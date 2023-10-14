/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:53:57 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:53:58 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_list_syntax(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	if (!tmp)
		ft_clear_list_exit(list, EMPTYMAP);
	while (tmp)
	{
		if (tmp->type == ERROR_LINE)
			ft_clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		else if (tmp->type == TEXTURE_LINE \
				&& ft_check_cardinal_syntax(tmp->line))
			ft_clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		else if (tmp->type == COLOR_LINE && ft_check_fc_syntax(tmp->line))
			ft_clear_list_syntax_exit(list, i, tmp->line, SYNTAX);
		else if (tmp->type == MAP_LINE && ft_is_map_str(tmp->line))
			ft_clear_list_syntax_exit(list, i, tmp->line, WCHARMAP);
		i++;
		tmp = tmp->next;
	}
	ft_check_last_element(list);
}
