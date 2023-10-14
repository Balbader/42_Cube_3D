/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:01:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 16:01:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
	@brief fill an int tab with given value, usually 0

	@param tab pointer to the tab
	@param tab_size size of the tab
	@param value value to fill the tab with
	@return nothing
**/
void	ft_bzero_int_tab(int *tab, int  tab_size, int value)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		tab[i] = value;
		i++;
	}
}
