# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 15:06:14 by mszczesn          #+#    #+#              #
#    Updated: 2016/04/01 13:15:26 by ndauteui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CFLAGS += -Wall -Werror -Wextra -g

SRC =  srcs/lexer.c srcs/tlist.c srcs/match_token.c srcs/main.c srcs/op.c srcs/chartohexa.c srcs/ocp.c \
	   srcs/opcodetofile.c srcs/utils.c srcs/check.c srcs/createfile.c srcs/get_addresses.c srcs/check_params.c \
	   srcs/check_addresses.c

HEADER = asm.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	make -C libft/
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ) -L ft_printf/ -L libft/ -lft -lftprintf
	@echo "\033[0;32m   _____ 									"
	@echo "\033[0;32m  / ____|									"
	@echo "\033[0;32m | |     ___  _ __ _____      ____ _ _ __  "
	@echo "\033[0;32m | |    / _ \| '__/ _ \ \ /\ / / _' | '__| "
	@echo "\033[0;32m | |___| (_) | | |  __/\ V  V / (_| | |    "
	@echo "\033[0;32m  \_____\___/|_|  \___| \_/\_/ \__,_|_|    "
	@echo "\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ft_printf/ clean
	make -C libft/ clean
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
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
