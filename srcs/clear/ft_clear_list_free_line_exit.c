/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list_free_line_exit.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:59:34 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 12:59:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_list_free_line_exit(t_list **list, char *line)
{
	ft_lst_clear(list);
	free(line);
	ft_print_exit_error(GNLFAIL);
}
