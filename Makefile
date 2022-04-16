NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c
RM		= rm -rf
SRCS	= so_long.c validate.c validate2.c get_next_line.c \
			check_utils.c setup.c close.c gameplay.c \
			animations/animation_utils.c 

OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS) minilibx libft libft_printf
		$(CC) $(OBJS) -Lminilibx_opengl_20191021 -lmlx -Llibft -lft \
		-Lft_printf -lftprintf \
		-framework OpenGL -framework AppKit -lz -o $@

minilibx:
		make -C minilibx_opengl_20191021

libft	:
		make -C libft

libft_printf:
		make -C ft_printf

clean	:
		$(RM) $(OBJS)
		make -C minilibx_opengl_20191021 clean
		make -C libft clean
		make -C ft_printf clean

fclean	: clean
		$(RM) $(NAME)
		$(RM) libft/libft.a

re		: fclean all

.PHONY	: all bonus clean fclean re minilibx libft
		