NAME	=	cub3D
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3
LFLAGS	=	-L libft -lft -L minilibx-linux -lmlx -L/usr/lib/X11 -lX11 -lXext -lm
IFLAGS	=	-Iincludes -Ilibft -Iminilibx-linux -I/usr/include/X11
RM		=	rm -rf
SRC		=	src/main.c src/parser/parser_error_check_alt.c src/parser/parser_map_check.c src/parser/parser_map_check_alt.c src/parser/parser_error_check.c src/parser/parser_get_map.c \
			src/game_data/game_data_destroy.c src/game_data/game_data_img_init.c src/game_data/game_data_init.c src/handler/keypress_handler.c \
			src/handler/mouse_handler.c src/map/map_out_of_bounds.c src/player/player_move.c src/render/render_frame.c \
			src/game_exit.c src/game_loop.c src/setup_hooks.c src/render/render_vert.c src/handler/keyrelease_handler.c \
			src/utils/is_nsew.c src/render/render_frame_alt.c src/put_error.c
OBJS	=	$(SRC:.c=.o)
LFT		=	libft/libft.a
MLX		=	minilibx-linux/libmlx.a

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(LFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(NAME)

$(LFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

all:		$(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C minilibx-linux clean

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(LFT)
	$(RM) $(MLX)

re:			fclean all

.PHONY:		all clean fclean re
