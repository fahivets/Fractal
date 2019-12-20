NAME = fractol

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./inc/

LIB_DIR = ./libft/

SRC = main.c threads.c fractals_types.c tools.c hooks.c mouse.c params.c info.c parsing.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror -I /usr/local/include

MLX_F = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	make -C $(LIB_DIR)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(MLX_F) $(LIB_DIR)libft.a

$(LIB):
	make -C $(LIB_DIR) fclean

$(OBJ_DIR):
	mkdir obj

$(OBJ_DIR)%.o: %.c
	gcc -c $(FLAGS) $< -o $@ -I $(INC_DIR)

clean:
	make -C libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

vpath %.c $(SRC_DIR)
