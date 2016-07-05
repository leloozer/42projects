# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 14:26:54 by mszczesn          #+#    #+#              #
#    Updated: 2016/06/13 17:48:55 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

CFLAGS += -Wall -Wextra -Werror -g

SRC =  main.c key.c key2.c raytracer.c raytracer2.c draw.c lvl.c

HEADER = w3d.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C ft_printf/
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ) -L libft/ -L ft_printf/ -lft -lftprintf -lmlx -framework OpenGL -framework AppKit
	@echo "\033[0;32m                  _______  _        _______  ______   ______  "
	@echo "\033[0;32m	|\     /|(  ___  )( \      (  ____ \/ ___  \ (  __  \ "
	@echo "\033[0;32m	| )   ( || (   ) || (      | (    \/\/   \  \| (  \  )"
	@echo "\033[0;32m	| | _ | || |   | || |      | (__       ___) /| |   ) |"
	@echo "\033[0;32m	| |( )| || |   | || |      |  __)     (___ ( | |   | |"
	@echo "\033[0;32m	| || || || |   | || |      | (            ) \| |   ) |"
	@echo "\033[0;32m	| () () || (___) || (____/\| )      /\___/  /| (__/  )"
	@echo "\033[0;32m	(_______)(_______)(_______/|/       \______/ (______/ "
	@echo "\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft/ clean
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
	make -C libft/ fclean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
