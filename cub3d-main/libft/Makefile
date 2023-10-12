FUNC	=	isalpha isdigit isalnum isascii isprint strlen memset \
			bzero memcpy memmove strlcpy strlcat toupper tolower \
			strchr strrchr strncmp memchr memcmp strnstr atoi calloc \
			strdup substr strtrim split strjoin itoa strmapi striteri \
			putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstadd_front \
			lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap \
			printf ptoa xtoa utoa ctoa printf_utils get_next_line max strndup \
			isspace

SRC		=	$(addprefix src/, $(addsuffix .c, $(addprefix ft_, $(FUNC))))

OBJS	=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	libft.a


all: 		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $^

clean:
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		clean fclean all re
