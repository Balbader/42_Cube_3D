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

MEMORY_DIR			:=	memory/
MEMORY_FILES		:=	\
						ft_free_textures.c \
						ft_free_world.c
MEMORY				:=	$(addprefix $(MEMORY_DIR), $(MEMORY_FILES))

MOVEMENTS_DIR		:=	movements/
MOVEMENTS_FILES		:=	\
						ft_move.c \
						ft_rotate.c
MOVEMENTS			:=	$(addprefix $(MOVEMENTS_DIR), $(MOVEMENTS_FILES))

PARSING_DIR			:=	parsing/
PARSING_FILES		:=	\
						ft_parse_color.c \
						ft_parse_line.c \
						ft_parse_next_line.c \
						ft_parse_resolution.c \
						ft_parse_texture.c
PARSING				:=	$(addprefix $(PARSING_DIR), $(PARSING_FILES))

RAYCASTING_DIR		:=	raycasting/
RAYCASTING_FILES	:=	\
						ft_check_hit.c \
						ft_draw_textured_line.c \
						ft_init_vars.c \
						ft_run_dda.c
RAYCASTING			:=	$(addprefix $(RAYCASTING_DIR), $(RAYCASTING_FILES))

SPRITES_DIR			:=	sprites/
SPRITES_FILES		:=	\
						ft_compute_distances.c \
						ft_draw_sprite.c \
						ft_draw_sprite_line.c \
						ft_draw_sprites.c \
						ft_sort_sprites.c
SPRITES				:=	$(addprefix $(SPRITES_DIR), $(SPRITES_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						ft_atoi.c \
						ft_calloc.c \
						ft_char_in_str.c \
						ft_flip_pix.c \
						ft_get_screen_pixel.c \
						ft_get_tex_color.c \
						ft_load_texture.c \
						ft_load_textures.c \
						ft_nb_to_mem.c \
						ft_remove_spaces.c \
						ft_set_screen_pixel.c \
						ft_strcmp.c\
						ft_trim.c \
						ft_write_bmp_header.c \
						get_next_line.c \
						get_next_line_utils.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

##################################
#   		INGREDIENTS 		 #
##################################
INC_DIR				:=	./inc/

SRCS_DIR			:=	./srcs/
SRCS				:=	\
						$(CONTROLLER) \
						$(DRAW) \
						$(ERR_CHECK) \
						$(INIT) \
						$(MAP) \
						$(MEMORY) \
						$(MOVEMENTS) \
						$(PARSING) \
						$(RAYCASTING) \
						$(SPRITES) \
						$(UTILS) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

MLX					:=	inc/mlx_linux/libmlx.a
INC_MLX				:=	./inc/mlx_linux/
LIB					:=	-L ./inc/mlx_linux -lmlx -lXext -lX11

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)


CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g3 # -fsanitize=address
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
