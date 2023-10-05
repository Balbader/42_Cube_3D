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
NAME			:=	cub3d


##################################
#    	    SRCS FILES			 #
##################################


##################################
#   		INGREDIENTS 		 #
##################################
INC_DIR				:=	./inc/

SRCS_DIR			:=	./srcs/
SRCS				:=	main.c
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
