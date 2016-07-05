# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 15:06:14 by mszczesn          #+#    #+#              #
#    Updated: 2016/03/04 16:34:57 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS += -Wall -Werror -Wextra -g


SRC =  get_next_line.c ft_atoi.c ft_atoll.c ft_strchr.c ft_strcmp.c ft_strdup.c  ft_strsearch.c\
	   ft_memcpy.c ft_strjoin.c ft_strnew.c ft_strsub.c ft_strlen.c ft_strsplit.c ft_putstr.c\
	   parse.c queue.c check.c error.c anthill_s_e.c pushback.c connector.c ft_connector2.c free.c \
	   main.c \

HEADER = lem_in.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ) -L ft_printf/ -lftprintf
	@echo "\033[0;32m ______                        _____         "
	@echo "\033[0;32m ___  / _____   ________       ___(_)  ____  "
	@echo "\033[0;32m __  /  _/ _ \_/ __  __ \________/ /__/ __ \ "
	@echo "\033[0;32m _  /___/  __/  / / / / //______/ / _/ / / / "
	@echo "\033[0;32m /_____/\___//_/ /_/ /_/       /_/  /_/ /_/  "

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ft_printf/ clean
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
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
