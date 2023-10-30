/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_all_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:51:51 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 12:51:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_all_exit(t_data **data, t_list **list, char *msg)
{
	if (*list)
		ft_lst_clear(list);
	if (data)
		ft_clear_data(data);
	ft_print_exit_error(msg);
}
