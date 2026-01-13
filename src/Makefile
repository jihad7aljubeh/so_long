NAME = so_long
CC = cc
CFLAGS = -Werror -Wextra -Wall

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

SRCS = Initialize.c main.c utils.c val_utils1.c val_utils2.c flood_fill.c \
       flood_fill2.c render.c cleanup.c gnl/get_next_line.c gnl/get_next_line_utils.c libft.c moves.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
