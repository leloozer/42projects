# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 14:26:54 by mszczesn          #+#    #+#              #
#    Updated: 2016/07/07 14:12:18 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CFLAGS += -Wall -Werror -Wextra -g

SRC =  main.c prompt.c function.c builtin.c builtin2.c

HEADER = minishell.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C ft_printf/
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ) -L libft/ -L ft_printf/ -lft -lftprintf
	@echo "\033[0;32m            _       _     _          _ _ " 
	@echo "\033[0;32m  _ __ ___ (_)_ __ (_)___| |__   ___| | |"
	@echo "\033[0;32m |  _   _ \| |  _ \| / __|  _ \ / _ \ | |"
	@echo "\033[0;32m | | | | | | | | | | \__ \ | | |  __/ | |"
	@echo "\033[0;32m |_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|"
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
