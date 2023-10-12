/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:21:44 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 13:23:44 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_error(int error)
{
	if (error == E_DUPLICATE_TEXTURE)
		ft_putstr_fd("Error\nDuplicate texture\n", 2);
	else if (error == E_SYNTAX_ERROR)
		ft_putstr_fd("Error\nColor syntax error\n", 2);
	return (error);
}

int	put_map_error(char *map_path)
{
	ft_putstr_fd("Error\n", 2);
	perror(map_path);
	return (1);
}
