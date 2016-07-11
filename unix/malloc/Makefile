# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:46:46 by mszczesn          #+#    #+#              #
#    Updated: 2016/07/11 19:30:26 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_malloc.so

CFLAGS += -Wall -Werror -Wextra

SRC = malloc.c\

HEADER = malloc.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		ar r $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		gcc $(CFLAGS) -c $< -o $@

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
