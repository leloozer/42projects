# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 15:06:14 by mszczesn          #+#    #+#              #
#    Updated: 2016/03/25 16:53:06 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Colleen

CFLAGS +=  -Wall -Werror -Wextra -g

SRC = Colleen.c 

HEADER = colleen.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;32m Colleen ----> GO "
	@echo "\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	@echo "\033[0;31m  (         (                 (     "
	@echo "\033[0;31m  )\ )      )\ )      *   )   )\ )  "
	@echo "\033[0;31m (()/(  (  (()/( (    )  /(( (()/(  "
	@echo "\033[0;31m  /(_)) )\  /(_)))\  ( )(_))\ /(_)) "
	@echo "\033[0;31m (_))_ ((_)(_)) ((_)(_(_()|(_|_))_  "
	@echo "\033[0;31m  |   \| __| |  | __|_   _| __|   \ "
	@echo "\033[0;31m  | |) | _|| |__| _|  | | | _|| |) |"
	@echo "\033[0;31m  |___/|___|____|___| |_| |___|___/ "
	@echo "\033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
