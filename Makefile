SRCS		=	ft_checkmap.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_printmap.c \
				ft_readmap.c \
				libft.c \
				so_long.c \
				start_game.c \
				hooks.c \
				move.c \
				close.c \
				ft_checkmap_utils.c \
				ft_checkmap_more_utils.c

OBJS		= $(SRCS:.c=.o)

CC		= clang
RM		= rm -rf

CFLAGS = -Wall -Wextra -Werror -g3

NAME=	so_long

PATH_MLX		=./minilibx


%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

LINUX		= -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

$(NAME): $(OBJS)
		make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS) minilibx/libmlx_Linux.a $(LINUX) -o $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)

fclean:		clean
		make -C $(PATH_MLX) clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
