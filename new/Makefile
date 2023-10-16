# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 10:56:20 by baalbade          #+#    #+#              #
#    Updated: 2023/10/05 10:56:22 by baalbade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################
#   	      NAME 				 #
##################################
NAME				:=	cub3d


##################################
#    	    SRCS FILES			 #
##################################
CONTROLLER_DIR		:=	controller/
CONTROLLER_FILES	:=	\
						ft_pressed_key.c \
						ft_quit.c \
						ft_released_key.c
CONTROLLER			:=	$(addprefix $(CONTROLLER_DIR), $(CONTROLLER_FILES))

DRAW_DIR			:=	draw/
DRAW_FILES			:=	\
						ft_draw.c \
						ft_draw_walls.c
DRAW				:=	$(addprefix $(DRAW_DIR), $(DRAW_FILES))

ERR_CHECK_DIR		:=	err_check/
ERR_CHECK_FILES		:=	\
						ft_check_cell.c \
						ft_check_map.c \
						ft_check_parsing.c \
						ft_check_world.c
ERR_CHECK			:=	$(addprefix $(ERR_CHECK_DIR), $(ERR_CHECK_FILES))

INIT_DIR			:=	init/
INIT_FILES			:=	\
						ft_init_camera.c \
						ft_init_other_stuff.c \
						ft_init_screen.c \
						ft_init_sprites.c \
						ft_init_world.c \
						ft_read_file.c
INIT				:=	$(addprefix $(INIT_DIR), $(INIT_FILES))

MAP_DIR				:=	map/
MAP_FILES			:=	\
						ft_init_map.c \
						ft_init_map_cell.c \
						ft_parse_map.c \
						ft_parse_map_row.c \
						ft_read_map_row.c
MAP					:=	$(addprefix $(MAP_DIR), $(MAP_FILES))

INIT_DIR			:=	init/
INIT_FILES			:=	\
						ft_init_data.c \
						ft_init_map.c \
						ft_init_plyer.c \
INIT				:=	$(addprefix $(INIT_DIR), $(INIT_FILES))

LIBFT_DIR			:=	libft/
LIBFT_FILES			:=	\
						ft_atoi_base.c \
						ft_atoi.c \
						ft_isdigit.c \
						ft_lst_addback.c \
						ft_lst_clear.c \
						ft_lst_create.c \
						ft_lstlast.c \
						ft_lst_size.c \
						ft_memset.c \
						ft_split.c \
						ft_strchr.c \
						ft_strcmp.c \
						ft_strlen.c \
						ft_strncmp.c \
						ft_strndup.c \
						get_next_line.c
LIBFT				:=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILES))

MLX_DIR				:=	mlx/
MLX_FILES			:=	\
						ft_create_texture.c \
						ft_get_texture_pixel.c \
						ft_hook_mlx.c \
						ft_mlx_utils.c \
						ft_print_3d.c \
						ft_start_mlx.c \
						ft_xpm_file_and_addr.c \
						ft_xpm_texture_and_addr.c
MLX					:=	$(addprefix $(MLX_DIR), $(MLX_FILES))

PARSING_DIR			:=	parsing/
PARSING_FILES		:=	\
						ft_check_ac.c \
						ft_parsing.c
PARSING				:=	$(addprefix $(PARSING_DIR), $(PARSING_FILES))

RAYCASTING_DIR		:=	raycasting/
RAYCASTING_FILES	:=	\
						ft_horizontal_check.c \
						ft_horizontal_while.c \
						ft_vertical_check.c \
						ft_vertical_while.c
RAYCASTING			:=	$(addprefix $(RAYCASTING_DIR), $(RAYCASTING_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						ft_bzero_int_tab.c \
						ft_check_close.c \
						ft_check_extension.c \
						ft_check_open.c \
						ft_cloxe_all_textures.c \
						ft_copy_str.c \
						ft_create_trgb.c \
						ft_find_player_pos.c \
						ft_get_dir_radian.c \
						ft_get_hexa_rgn_values.c \
						ft_get_map_size.c \
						ft_get_player_info.c \
						ft_is_cardinal_char.c \
						ft_is_color_char.c \
						ft_is_map_str.c \
						ft_is_player.c \
						ft_nbrlen.c \
						ft_open_all_dir_textures.c \
						ft_open_all_textures.c \
						ft_print_array.c \
						ft_print_data.c \
						ft_print_exit_error.c \
						ft_print_list.c \
						ft_print_map.c \
						ft_set_line_type.c \
						ft_sub_trim.c \
						ft_ternary.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

##################################
#   		INGREDIENTS 		 #
##################################
INC_DIR				:=	./inc/

SRCS_DIR			:=	./srcs/
SRCS				:=	\
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

MLX					:=	inc/mlx_linux/libmlx.a
INC_MLX				:=	./inc/mlx_linux/
LIB					:=	-L ./inc/mlx_linux -lmlx -lXext -lX11 -lm

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)


CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g3 #-fsanitize=address
IFLAGS				:=	$(addprefix -I, $(INC_DIR))

RM					:=	rm -r -f
DIR_DUP				=	mkdir -p $(dir $@)


##################################
#   		COLORS 				 #
##################################
RED     			:= \033[0;31m
GREEN   			:= \033[0;32m
YELLOW  			:= \033[0;33m
RESET   			:= \033[0m


##################################
#   		RECIPES				 #
##################################
all: $(MLX) $(NAME)

$(NAME): $(OBJS)
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB) 
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(MLX):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling minilibx..."
	@make -sC $(INC_MLX) > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Minilibx ready!"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@make -sC $(INC_MLX) clean > /dev/null
	@$(RM) $(BUILD_DIR) $(DEPS)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@$(RM) $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
