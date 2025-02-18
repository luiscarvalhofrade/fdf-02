# Compiler LINUX - 42
CC = cc

# Flags
CFLAGS = -Wall -Werror -Wextra -g -I/usr/include -Imlx -Im -O3

SRC = 	fdf.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c \
		utils/ft_split.c \
		utils/ft_atoi.c \
		utils/ft_atoi_base.c \
		utils/ft_strchr.c \
		utils/ft_strncmp.c \
		utils/ft_strcmp.c \
		utils/ft_strrchr.c \
		is_valid_fdf.c \
		read_map.c \
		read_map_helper.c \
		read_map_utils.c \
		read_map_max_values.c \
		init_structs.c \
		start.c \
		projection.c \
		projection_utils.c \
		line_algo.c \
		win_control.c \
		draw.c \
		draw_utils.c \
		key_handle.c \
		key_handle_utils.c \

# Objects
OBJ = $(SRC:.c=.o)

# Program name
NAME = fdf

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXLIB) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"
leakfull:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} maps/test_maps/julia.fdf

clean:
	@rm -rf $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Program cleaned."

re: fclean all
	@echo "Recompiled $(NAME)."

.PHONY: all clean fclean re
