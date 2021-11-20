NAME = fdf
CC = gcc
PARAMS = -Wall -Wextra -Werror

INC_PATH = includes/
SRC_PATH = srcs/
OBJ_PATH = obj/

INC_NAME = fdf.h
MINILIBX_LIB_PATH = ./mlx_linux/libmlx_Linux.a
LIBFT_LIB_PATH = ./libft/libft.a
SRC_NAME =	main.c \
			get_next_line.c \
			get_next_line_utils.c \
			setenv.c \
			check_input.c \
			stock_input.c \
			hook.c \
			draw.c \
			bresenham.c

LIBX_LINUX_FLAGS = -lm -lbsd -lX11 -lXext

OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I inc/ -I libft/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[fdf] : $(DEF)Compilation..."
	@make -C libft
	@make -C mlx_linux
	@$(CC) $(PARAMS) $(OBJ) $(LIBFT_LIB_PATH) $(MINILIBX_LIB_PATH) ${LIBX_LINUX_FLAGS} -o $(NAME) $(INC) -L libft/
	@echo "$(RED)[fdf] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[fdf] :$(DEF) Compiling $@"
	@$(CC) $(PARAMS) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@make -C mlx_linux clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[fdf] : $(DEF)Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@make -C libft fclean
	@make -C mlx_linux clean
	@rm -rf $(NAME)
	@echo "$(RED)[fdf] : $(DEF)Full Cleaning               $(GRN)[OK]$(DEF)"

re: fclean all
