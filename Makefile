NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c -g
RM		= rm -rf
SRCS	= so_long.c
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

%.o		: %.c
		$(CC) $(CFLAGS) -Lminilibx_opengl_20191021 $< -o $@

$(NAME)	: $(OBJS)
		$(CC) $(OBJS) -Lminilibx_opengl_20191021 -lmlx \
		-framework OpenGL -framework AppKit -o $(NAME)

minilibx:
		make -C minilibx_opengl_20191021

clean	:
		$(RM) $(OBJS)
		make -C minilibx_opengl_20191021 clean

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all bonus minilibx clean fclean re
		