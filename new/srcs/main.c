/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:34:10 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 08:34:11 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	ft_parsing(argc, argv, &data);
	ft_start_mlx(data);
	ft_clear_data(&data);
	return (EXIT_SUCCESS);
}
