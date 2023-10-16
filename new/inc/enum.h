/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:28:26 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 09:28:27 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_player
{
	X_POS,
	Y_POS,
	X_PIXEL,
	Y_PIXEL,
	ANGLE,
	MAX_POS,
};

enum	e_img
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST,
	IMAGE,
	FLOOR_IMG,
	CEILING_IMG,
	MAX_IMG,
};

enum	e_type
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE,
};

enum	e_INFOS
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
};

enum	e_TEXTURE
{
	FLOORTEX = 0,
	CEILINGTEX,
	NORTHTEX,
	SOUTHTEX,
	WESTTEXT,
	EASTTEX,
};

enum	e_RGB
{
	RED_RGB = 0,
	GREEN_RGB,
	BLUE_RGB,
};

#endif // !ENUM_H
