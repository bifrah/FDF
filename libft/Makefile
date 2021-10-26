# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 14:27:45 by bifrah            #+#    #+#              #
#    Updated: 2021/06/27 14:11:28 by bifrah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRCS =		ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_strlen.c \
			ft_toupper.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
			ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ =	$(SRCS:.c=.o)

BONUS =		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_BONUS =	$(BONUS:.c=.o)

INCLUDES = ./
PARAMS = -Wall -Wextra -Werror

GRN= \033[92m
YEL= \033[93m
DEF= \033[0m


.PHONY: all bonus clean fclean re so

all: $(NAME)

$(NAME):
	@echo "$(YEL)[libft]$(DEF) : Compilation..."
	@$(CC) $(PARAMS) -I$(INCLUDES) -c $(SRCS)
	@ar -rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(YEL)[libft]$(DEF) : Compilation                 $(GRN)[OK]$(DEF)"

bonus:
	@echo "$(YEL)[libft]$(DEF) : Compilation Bonus..."
	@$(CC) $(PARAMS) -I$(INCLUDES) -c $(BONUS)
	@ar -rcs $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)
	@echo "$(YEL)[libft]$(DEF) : Compilation Bonus           $(GRN)[OK]$(DEF)"

clean:
	@rm -f *.o
	@echo "$(YEL)[libft]$(DEF) : Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YEL)[libft]$(DEF) : Full Cleaning               $(GRN)[OK]$(DEF)"

re: fclean all

so:
	$(CC) -nostartfiles -fPIC -c $(PARAMS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJ_BONUS)
