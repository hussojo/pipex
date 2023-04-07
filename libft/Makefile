# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:57:07 by jhusso            #+#    #+#              #
#    Updated: 2023/04/07 08:43:37 by jhusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_strchr \
	ft_strcpy \
	ft_strdup \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_tolower \
	ft_toupper \
	ft_substr \
	ft_strjoin \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_strmapi \
	ft_striteri \
	ft_strtrim \
	ft_itoa \
	ft_split \
	ft_pipex_split \
	free_array \

SRC_B =	ft_lstnew_bonus \
	ft_lstadd_front_bonus \
	ft_lstsize_bonus \
	ft_lstlast_bonus \
	ft_lstadd_back_bonus \
	ft_lstdelone_bonus \
	ft_lstmap_bonus \
	ft_lstclear_bonus \
	ft_lstiter_bonus \


SRC_FILES = $(addsuffix .c, $(SRC))

OBJECT_FILES = $(SRC_FILES:.c=.o)

SRC_B_FILES = $(addsuffix .c, $(SRC_B))

OBJECT_B_FILES = $(SRC_B_FILES:.c=.o)

H_FILES = libft.h

CC = cc
RM = rm -f
BUILD_FLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

.PHONY: bonus
bonus: $(SRC_B_FILES:.c=.o)

$(NAME): $(SRC_FILES)
	@$(CC) -c $(BUILD_FLAGS) $(SRC_FILES) -I $(H_FILES)
	@ar rcs $(NAME) $(OBJECT_FILES)

$(SRC_B_FILES:.c=.o):
	@$(CC) -c $(BUILD_FLAGS) $(SRC_B_FILES)
	@ar rus $(NAME) $(OBJECT_B_FILES)

.PHONY: clean
clean:
	@rm -f $(OBJECT_FILES) $(OBJECT_B_FILES)

.PHONY:
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all

