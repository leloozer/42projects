# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 13:55:46 by mszczesn          #+#    #+#              #
#    Updated: 2015/12/16 14:01:03 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	  ft_map.c\
	  ft_openandmalloc.c\
	  ft_checkpiece.c\
	  ft_resolve.c\

HEADER = fillit.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	gcc -Werror -Wall -Wextra -c $(SRC) -I./
	gcc -Werror -Wall -Wextra $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: clean all
	fclean $(NAME)

.PHONY : re fclean clean all
