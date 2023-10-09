/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:01:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/05 11:01:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "structures.h"
# include "mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>

/***************************************************************** controller */
int	ft_pressed_key(int key, t_world *world);
int	ft_quit(t_world *world, t_bool exit_value);
int	ft_released_key(int key, t_world *world);

/*********************************************************************** draw */
void	ft_draw(t_world *world);
void	ft_draw_walls(t_world *world);

/****************************************************************** err_check */
void	ft_check_map(t_world *world);
void	ft_check_world(t_world *world);
void	ft_check_parsing(t_world *world, char *msg, int line);
t_bool	ft_check_cell(t_world *world, int i, int j);

/*********************************************************************** init */
#endif	
