/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cardinal_duplicates.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:41:31 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:41:32 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_cardinal_duplicates(t_list **list, int *dup, char *str, int i)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		dup[NORTH] += 1;
		if (dup[NORTH] > 1)
			ft_clear_list_syntax_exit(list, i, str, DUPNO);
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		dup[SOUTH] += 1;
		if (dup[SOUTH] > 1)
			ft_clear_list_syntax_exit(list, i, str, DUPSO);
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		dup[WEST] += 1;
		if (dup[WEST] > 1)
			ft_clear_list_syntax_exit(list, i, str, DUPWE);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		dup[EAST] += 1;
		if (dup[EAST] > 1)
			ft_clear_list_syntax_exit(list, i, str, DUPEA);
	}
}
