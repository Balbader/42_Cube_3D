/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_constants.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:20:52 by eloevenb          #+#    #+#             */
/*   Updated: 2023/05/10 12:41:48 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONSTANTS_H
# define CUB3D_CONSTANTS_H

# define E_OK 0
# define E_NULLPTR 1
# define ERR_NPTR "Error\nNull pointer\n"
# define E_SYNTAX_ERROR 2
# define ERR_SYNTAX "Error\nSyntax error\n"
# define E_FILE 3
# define E_MISSING_TEXTURE 4
# define ERR_TEXT "Error\nMissing texture\n"
# define E_INVALID_LINE 5
# define ERR_LINE "Error\nInvalid line\n"
# define E_DUPLICATE_TEXTURE 6
# define ERR_DUP_TEXT "Error\nDuplicate texture\n"
# define E_EMPTY_LINE 7
# define ERR_EMPTY_LINE "Error\nEmpty line\n"
# define E_OPEN_MAP 8
# define ERR_OPEN_MAP "Error\nOpen map\n"
# define E_INVALID_CHAR 9
# define ERR_INV_CHAR "Error\nInvalid char\n"
# define E_SEVERAL_CHAR 10
# define ERR_SEV_CHAR "Error\nSeveral players\n"
# define E_NO_CHAR 11
# define ERR_NO_CHAR "Error\nNo player\n"
# define E_SEVERAL_MAPS 11
# define ERR_SEV_MAP "Error\nSeveral maps\n"

# define EAST_COLOR 0x246927
# define WEST_COLOR 0x218225
# define NORTH_COLOR 0x28a13c
# define SOUTH_COLOR 0x48ab58

# define CEILING_COLOR 0x002594
# define FLOOR_COLOR 0x940000

# define WORLD_SCALE 3.23
# define CAMERA_PLANE 2.0
# define WIN_HEIGHT 600
# define WIN_WIDTH 920
# define WIN_TITLE "cub3d"

# define KEY_RLEFT 0
# define KEY_RRIGHT 1
# define KEY_FORWARD 2
# define KEY_BACKWARD 3
# define KEY_LEFT 4
# define KEY_RIGHT 5

# ifdef KEYBOARD_FR

# endif

# ifndef KEYBOARD_FR

# endif

#endif