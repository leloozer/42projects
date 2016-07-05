# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 15:06:14 by mszczesn          #+#    #+#              #
#    Updated: 2016/06/24 21:22:45 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS += -Wall -Werror -Wextra -g


SRC = 	parse.c opendir.c opendir2.c print.c print2.c sort.c sort2.c sort3.c recup_env.c recup_env2.c free.c option.c\
	ft_strjoin.c ft_strsplit.c ft_strsub.c ft_strcmp.c ft_strlen.c ft_strdup.c\
	ft_intlen.c ft_putendl_fd.c main.c

HEADER = ft_ls.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ)  -L ft_printf/ -lftprintf
	@echo "\033[0;32m    ___  __             ___              "
	@echo "\033[0;32m  / ___\/\ \__         /\_ \             "
	@echo "\033[0;32m /\ \__/\ \ ,_\        \//\ \     ____   "
	@echo "\033[0;32m \ \ ,__\ \ \ \/         \ \ \   / ,__\  "
	@echo "\033[0;32m  \ \ \_/ \ \ \_          \_\ \_/\__,  \ "
	@echo "\033[0;32m   \ \_\   \ \__\         /\____\/\____/ "
	@echo "\033[0;32m    \/_/    \/__/  _______\/____/\/___/  "
	@echo "\033[0;32m                  /\______\              "
	@echo "\033[0;32m                  \/______/              "
	@echo "\033[0m"

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
