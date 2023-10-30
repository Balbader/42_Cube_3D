/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color_duplicates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:40:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:40:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_color_duplicates(t_list **list, int *dup, char *str, int i)
{
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		dup[FLOOR] += 1;
		if (dup[FLOOR] > 1)
			ft_clear_list_syntax_exit(list, i, str, DUPF);
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		dup[CEILING] += 1;
		if (dup[CEILING] > 1)
			ft_clear_list_syntax_exit(list, i, str, DUPC);
	}
}
