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
NAME				:=	cub3D


##################################
#    	    SRCS FILES			 #
##################################
CLEAR_DIR			:=	clear/
CLEAR_FILES			:=	\
						ft_clear_all_exit.c \
						ft_clear_data.c \
						ft_clear_data_exit.c \
						ft_clear_data_nclosedmap_exit.c \
						ft_clear_data_syntax_exit.c \
						ft_clear_list_exit.c \
						ft_clear_list_free_line_exit.c \
						ft_clear_list_syntax_exit.c \
						ft_clear_mlx_fd_data_exit.c
CLEAR				:=	$(addprefix $(CLEAR_DIR), $(CLEAR_FILES))

DUP_ERR_DIR			:=	duplicates_err/
DUP_ERR_FILES		:=	\
						ft_check_cardinal_duplicates.c \
						ft_check_color_duplicates.c \
						ft_check_list_duplicates.c \
						ft_check_missing_lines.c
DUP_ERR				:=	$(addprefix $(DUP_ERR_DIR), $(DUP_ERR_FILES))

MAP_ERR_DIR			:=	map_err/
MAP_ERR_FILES		:=	\
						ft_check_closed_map.c \
						ft_check_first_last_char.c \
						ft_check_inner_map.c \
						ft_check_player_count.c \
						ft_check_side.c \
						ft_is_not_only_one_or_space_str.c
MAP_ERR				:=	$(addprefix $(MAP_ERR_DIR), $(MAP_ERR_FILES))

SYNTAX_ERR_DIR		:=	syntax_err/
SYNTAX_ERR_FILES	:=	\
						ft_check_cardinal_syntax.c \
						ft_check_fc_syntax.c \
						ft_check_last_element.c \
						ft_check_list_syntax.c \
						ft_check_splitted_map.c
SYNTAX_ERR			:=	$(addprefix $(SYNTAX_ERR_DIR), $(SYNTAX_ERR_FILES))

TEXTURES_ERR_DIR	:=	textures_err/
TEXTURES_ERR_FILES	:=	\
						ft_check_open_textures.c \
						ft_check_textures_extensions.c \
						ft_check_texture_size.c \
						ft_check_value_limits.c \
						ft_close_dir_error_exit.c \
						ft_close_error_exit.c
TEXTURES_ERR		:=	$(addprefix $(TEXTURES_ERR_DIR), $(TEXTURES_ERR_FILES))

ERR_CHECK_DIR		:=	err_check/
ERR_CHECK_FILES		:=	\
						$(DUP_ERR) \
						$(MAP_ERR) \
						$(SYNTAX_ERR) \
						$(TEXTURES_ERR)
ERR_CHECK			:=	$(addprefix $(ERR_CHECK_DIR), $(ERR_CHECK_FILES))

FILL_DIR			:=	fill/
FILL_FILES			:=	\
						ft_fill_data.c \
						ft_fill_list.c \
						ft_fill_map.c \
						ft_fill_rgb.c \
						ft_fill_texture.c
FILL				:=	$(addprefix $(FILL_DIR), $(FILL_FILES))

FREE_DIR			:=	free/
FREE_FILES			:=	\
						ft_free_array.c \
						ft_free_mlx.c \
						ft_free_texture.c
FREE				:=	$(addprefix $(FREE_DIR), $(FREE_FILES))

INIT_DIR			:=	init/
INIT_FILES			:=	\
						ft_init_data.c \
						ft_init_map.c \
						ft_init_player.c
INIT				:=	$(addprefix $(INIT_DIR), $(INIT_FILES))

LIBFT_DIR			:=	libft/
LIBFT_FILES			:=	\
						ft_atoi_base.c \
						ft_atoi.c \
						ft_isdigit.c \
						ft_lstaddback.c \
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
						ft_close_all_textures.c \
						ft_copy_str.c \
						ft_create_trgb.c \
						ft_find_player_pos.c \
						ft_get_dir_radian.c \
						ft_get_hexa_rgb_values.c \
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
						ft_set_line_type.c \
						ft_sub_trim_str.c \
						ft_ternary.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

##################################
#   		INGREDIENTS 		 #
##################################
INC_DIR				:=	./inc/

SRCS_DIR			:=	./srcs/
SRCS				:=	\
						$(CLEAR) \
						$(ERR_CHECK) \
						$(FILL) \
						$(FREE) \
						$(INIT) \
						$(LIBFT) \
						$(MLX) \
						$(PARSING) \
						$(RAYCASTING) \
						$(UTILS) \
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
