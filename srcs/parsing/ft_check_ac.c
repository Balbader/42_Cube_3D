/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:02:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/30 13:02:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_ac(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_check_extension(av[1], ".cub"))
			ft_print_exit_error(WEXT);
	}
	else if (ac == 1)
		ft_print_exit_error(MARG);
	else if (ac > 2)
		ft_print_exit_error(TMARG);
}
