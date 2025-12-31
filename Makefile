NAME        := so_long

CC          := cc
CFLAGS      := -Werror -Wextra -Wall

# Directories
SRC_DIR     := Srcs
INC_DIRS    := . Includes minilibx-linux

# Add include paths (for local headers and MiniLibX headers)
CFLAGS      += $(addprefix -I,$(INC_DIRS))

# MiniLibX (vendored)
MLX_DIR     := minilibx-linux
MLX_LIB     := $(MLX_DIR)/libmlx.a

# Linux link flags for MiniLibX
MLX_FLAGS   := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

# Sources
SRCS := Initialize.c main.c utils.c val.c val_utils1.c val_utils2.c flood_fill.c \
        gnl/get_next_line.c gnl/get_next_line_utils.c libft.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

# Main target
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# MiniLibX target: clone and build if missing
$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MiniLibX not found. Cloning..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@echo "Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

# Clean object files
clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR)

# Full clean
fclean: clean
	@rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
