/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:01:36 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/05 11:01:37 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/******************************************************************* 1st Line */
# define ESCAPE 65307

/******************************************************************* 2nd Line */
# define TILDE 96
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define FIVE 53
# define SIX 54
# define SEVEN 55
# define EIGHT 56
# define NINE 57
# define ZERO 48
# define LESS 45
# define EQUAL 61
# define DELETE 65288

/******************************************************************* 3rd Line */
# define TAB 65289
# define Q 113
# define W 119
# define E 101
# define R 114
# define T 116
/* #define Y 121 */
# define U 117
# define I 105
# define O 111
# define P 112
# define BRACKET_LEFT 91
# define BRACKET_RIGHT 93
# define BACK_SLASH 92

/******************************************************************* 4th Line */
# define CAPS_LOCK 65509
# define A 97
# define S 115
# define D 100
# define F 102
# define G 103
# define H 104
# define J 106

/* #define K 107 */
# define L 108
# define ENTER 65293

/******************************************************************* 5th Line */
# define SHIFT 65505
# define Z 122

/* #define X 120 */
# define C 99
# define V 118
# define B 98
# define N 110
# define M 109

/******************************************************************* 6th Line */
# define CONTROL_LEFT 65507
# define OPTION_LEFT 65513
# define SPACE 32
# define COMMAND_RIGHT 65516
# define OPTION_RIGHT 65514
# define CONTROL_RIGHT 65508

/********************************************************************* Colors */
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

/********************************************************************* Arrows */
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

/********************************************************************* ERRORS */

# define KYU "🔮🧡🍁🐞🍄🍀🌸🐹🌳🦊🐼🌿🧡🦊🧡🌿🐼🦊🌳🐹🌸🍀🍄🐞🍁🧡🔮\n"
# define LAUNCH "🍀🌸🦊    Launch ./cub3D map_filename.cub     🦊🌸🍀\n"
# define BIE "🍀🌸🦊                                          🦊🌸🍀\n"
# define LIST "🍀🌸🦊          Linked list of map file         🦊🌸🍀\n"
# define GAME "🍀🌸🦊                Game Infos                🦊🌸🍀\n"
# define MAP "🍀🌸🦊                  Map                     🦊🌸🍀\n"

# define MARG "🍀🌸🦊             Missing Map file             🦊🌸🍀\n"
# define TMARG "🍀🌸🦊           Too Many Arguments             🦊🌸🍀\n"
# define WEXT "🍀🌸🦊           Wrong Map Extension            🦊🌸🍀\n"
# define OPENERR "🍀🌸🦊           Can't Open Map File            🦊🌸🍀\n"
# define OPENDIRERR "🍀🌸🦊      Map is  Directory not a File        🦊🌸🍀\n"
# define CLOSEERR "🍀🌸🦊           Can't Close Map File            🦊🌸🍀\n"
# define CLOSETEX "🍀🌸🦊         Can't Close Texture File          🦊🌸🍀\n"
# define EMPTYMAP "🍀🌸🦊               Map is empty               🦊🌸🍀\n"
# define SYNTAX "🍀🌸🦊       Wrong line syntax in mapfile       🦊🌸🍀\n"
# define DUPNO "🍀🌸🦊          Multiple North textures         🦊🌸🍀\n"
# define DUPSO "🍀🌸🦊          Multiple South textures         🦊🌸🍀\n"
# define DUPWE "🍀🌸🦊          Multiple West textures          🦊🌸🍀\n"
# define DUPEA "🍀🌸🦊          Multiple East textures          🦊🌸🍀\n"
# define DUPF "🍀🌸🦊       Multiple Floor colors line         🦊🌸🍀\n"
# define DUPC "🍀🌸🦊      Multiple Ceiling colors lines       🦊🌸🍀\n"
# define MISSNO "🍀🌸🦊        North texture line missing        🦊🌸🍀\n"
# define MISSSO "🍀🌸🦊        South texture line missing        🦊🌸🍀\n"
# define MISSWE "🍀🌸🦊        West texture line missing         🦊🌸🍀\n"
# define MISSEA "🍀🌸🦊        East texture line missing         🦊🌸🍀\n"
# define MISSF "🍀🌸🦊         FLoor color line missing         🦊🌸🍀\n"
# define MISSC "🍀🌸🦊        Ceiling color line missing        🦊🌸🍀\n"
# define ENDFILE "🍀🌸🦊       Map must be the last element       🦊🌸🍀\n"
# define DATAFAIL "🍀🌸🦊             Data Malloc fail             🦊🌸🍀\n"
# define NORTHFAIL "🍀🌸🦊     Data North Texture Malloc fail       🦊🌸🍀\n"
# define SOUTHFAIL "🍀🌸🦊     Data South Texture Malloc fail       🦊🌸🍀\n"
# define WESTFAIL "🍀🌸🦊      Data West Texture Malloc fail       🦊🌸🍀\n"
# define EASTFAIL "🍀🌸🦊      Data East Texture Malloc fail       🦊🌸🍀\n"
# define FLOORFAIL "🍀🌸🦊         Data Floor RGB Malloc fail       🦊🌸🍀\n"
# define CEILINGFAIL "🍀🌸🦊       Data Ceiling RGB Malloc fail       🦊🌸🍀\n"
# define SUBTRIMFAIL "🍀🌸🦊           Sub trim Malloc fail           🦊🌸🍀\n"
# define COMASFAIL "🍀🌸🦊     Split RGB on comas Malloc fail       🦊🌸🍀\n"
# define MISSRGB "🍀🌸🦊     Missing RGB value, three needed      🦊🌸🍀\n"
# define TMRGB "🍀🌸🦊     Too much RGB values, three needed    🦊🌸🍀\n"
# define BIGRGB "🍀🌸🦊             RGB value too big            🦊🌸🍀\n"
# define SYNTAXRGB "🍀🌸🦊          RGB value syntax error          🦊🌸🍀\n"

# define OPENDIRNOTEX "🍀🌸🦊       North Texture is Directory         🦊🌸🍀\n"
# define OPENDIRSOTEX "🍀🌸🦊       South Texture is Directory         🦊🌸🍀\n"
# define OPENDIRWETEX "🍀🌸🦊       West Texture is Directory          🦊🌸🍀\n"
# define OPENDIREATEX "🍀🌸🦊       East Texture is Directory          🦊🌸🍀\n"
# define OPENNOTEX "🍀🌸🦊        Can't Open North Texture          🦊🌸🍀\n"
# define OPENSOTEX "🍀🌸🦊        Can't Open South Texture          🦊🌸🍀\n"
# define OPENWETEX "🍀🌸🦊        Can't Open West Texture           🦊🌸🍀\n"
# define OPENEATEX "🍀🌸🦊        Can't Open East Texture           🦊🌸🍀\n"

# define EMPTYNOTEX "🍀🌸🦊         North Texture is empty             🦊🌸🍀\n"
# define EMPTYSOTEX "🍀🌸🦊         South Texture is empty             🦊🌸🍀\n"
# define EMPTYWETEX "🍀🌸🦊         West Texture is empty              🦊🌸🍀\n"
# define EMPTYEATEX "🍀🌸🦊         East Texture is empty              🦊🌸🍀\n"
# define WNOEXT "🍀🌸🦊      Wrong North Texture Extension       🦊🌸🍀\n"
# define WSOEXT "🍀🌸🦊      Wrong South Texture Extension       🦊🌸🍀\n"
# define WWEEXT "🍀🌸🦊      Wrong West Texture Extension        🦊🌸🍀\n"
# define WEAEXT "🍀🌸🦊      Wrong East Texture Extension        🦊🌸🍀\n"
# define SIZENOTEX "🍀🌸🦊     North Texture sie is not 64 x 64     🦊🌸🍀\n"
# define SIZESOTEX "🍀🌸🦊     South Texture sie is not 64 x 64     🦊🌸🍀\n"
# define SIZEWETEX "🍀🌸🦊      West Texture sie is not 64 x 64     🦊🌸🍀\n"
# define SIZEEATEX "🍀🌸🦊      East Texture sie is not 64 x 64     🦊🌸🍀\n"
# define MLXFAIL "🍀🌸🦊      Mlx init fail (nice try env -i)     🦊🌸🍀\n"
# define MAPFAIL "🍀🌸🦊           Map Malloc fail error          🦊🌸🍀\n"
# define WCHARMAP "🍀🌸🦊     Map is not only ' 01NSWE' chars      🦊🌸🍀\n"
# define SPLITMAP "🍀🌸🦊      Map is splitted by space line       🦊🌸🍀\n"

# define NCLOSEDMAP "🍀🌸🦊        Map is not closed by 1 chars      🦊🌸🍀\n"
# define ZEROPMAP "🍀🌸🦊             Map has no player            🦊🌸🍀\n"
# define MULTIPMAP "🍀🌸🦊       Map has more than one player       🦊🌸🍀\n"
# define GNLFAIL "🍀🌸🦊           Gnl Malloc fail error          🦊🌸🍀\n"
# define SCREENFAIL "🍀🌸🦊           Screen Malloc fail error        🦊🌸🍀\n"
# define IMGFAIL "🍀🌸🦊           Image Malloc fail error        🦊🌸🍀\n"
# define TEXFAIL "🍀🌸🦊          Texture Malloc fail error        🦊🌸🍀\n"
# define IMGTEXFAIL "🍀🌸🦊       Texture Image Malloc fail error     🦊🌸🍀\n"
# define MLXINITFAIL "🍀🌸🦊     Mlx init fail (nice try env -i)      🦊🌸🍀\n"
# define MLXWINFAIL "🍀🌸🦊          Mlx new window failed           🦊🌸🍀\n"
# define MLXIMGFAIL "🍀🌸🦊           Mlx new image failed           🦊🌸🍀\n"
# define MLXADDRFAIL "🍀🌸🦊         Mlx data address failed          🦊🌸🍀\n"

# define MAPCHAR "01NSWE"

#endif	
