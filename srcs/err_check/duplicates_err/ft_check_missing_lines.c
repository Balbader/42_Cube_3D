/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_missing_lines.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:38:54 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 11:38:57 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_missing_lines(t_list **list, int *dup)
{
	if (dup[NORTH] == 0)
		ft_clear_list_exit(list, MISSNO);
	else if (dup[SOUTH] == 0)
		ft_clear_list_exit(list, MISSSO);
	else if (dup[WEST] == 0)
		ft_clear_list_exit(list, MISSWE);
	else if (dup[EAST] == 0)
		ft_clear_list_exit(list, MISSEA);
	else if (dup[FLOOR] == 0)
		ft_clear_list_exit(list, MISSF);
	else if (dup[CEILING] == 0)
		ft_clear_list_exit(list, MISSC);
}
