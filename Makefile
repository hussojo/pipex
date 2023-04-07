# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 09:14:53 by jhusso            #+#    #+#              #
#    Updated: 2023/04/07 08:43:35 by jhusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -f
BUILD_FLAGS = -Wall -Wextra -Werror
#-fsanitize=address -static-libsan -g
LIBFT = ./libft
INCLUDE = ./libft/libft.h

SRC = main.c children.c pipex_utils.c

OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(NAME) : $(SRC) $(LIBFT)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(BUILD_FLAGS) $(SRC) -I $(INCLUDE) -L$(LIBFT) -lft

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
