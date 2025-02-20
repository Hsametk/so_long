# NAME=SO_LONG
# FT_PRINTF_PATH=srcs/ft_printf
# FT_PRINTF=$(FT_PRINTF_PATH)/libftprintf.a
# LIBFT_PATH=srcs/libft
# LIBFT=$(LIBFT_PATH)/libft.a
# MINILIBX_PATH=srcs/minilibx-linux
# MINILIBX=$(MINILIBX_PATH)/libmlx.a
# FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -l ftprintf -I $(FT_PRINTF_PATH)
# FT_LIBFT_LIB_FLAGS=-L $(LIBFT_PATH) -lft -I $(LIBFT_PATH)
# MINILIBX_LIB_FLAGS=-L $(MINILIBX_PATH) -l minilibix -I $(MINILIBX_PATH)
# CC=cc
# CFLAGS=-Lminilibx-linux -lm -lXext -lX11


# all: $(NAME)

# $(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX)
# 	$(CC) $(CFLAGS) ilk_deneme.c -o $(NAME) $(FT_PRINTF_LIB_FLAGS) $(FT_LIBFT_LIB_FLAGS) $(MINILIBX_LIB_FLAGS)

# $(LIBFT):
# 	make -s -C $(LIBFT_PATH)

# $(FT_PRINTF):
# 	make -s -C $(FT_PRINTF_PATH)

# $(MINILIBX):
# 	make -s -C $(MINILIBX_PATH)

# clean:
# 	make -s -C $(FT_PRINTF_PATH) clean
# 	make -s -C $(LIBFT_PATH) clean
# 	make -s -C $(MINILIBX_PATH) clean

# fclean:	clean
# 	$(RM) $(NAME) $(LIBFT) $(FT_PRINTF) $(MINILIBX)

# re: fclean all

# .PHONY: all clean fclean re

NAME=so_long

# Paths
FT_PRINTF_PATH=srcs/ft_printf
FT_PRINTF=$(FT_PRINTF_PATH)/libftprintf.a
LIBFT_PATH=srcs/libft
LIBFT=$(LIBFT_PATH)/libft.a
MINILIBX_PATH=srcs/minilibx-linux
MINILIBX=$(MINILIBX_PATH)/libmlx.a

# Compilation Flags
CC=cc
CFLAGS=-Wall -Wextra -Werror #-fsanitize=address
LIB_FLAGS=-L $(MINILIBX_PATH) -lmlx -lm -lXext -lX11
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -lftprintf -I $(FT_PRINTF_PATH)
FT_LIBFT_LIB_FLAGS=-L $(LIBFT_PATH) -lft -I $(LIBFT_PATH)

# Source File
SRC=so_long.c checker.c errors.c flood_fill.c create_image.c key_hook.c more_check.c free_functions.c read_map.c

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB_FLAGS) $(FT_PRINTF_LIB_FLAGS) $(FT_LIBFT_LIB_FLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

$(MINILIBX):
	make -C $(MINILIBX_PATH)

clean:
	make -C $(FT_PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(FT_PRINTF_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	make -C $(MINILIBX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
