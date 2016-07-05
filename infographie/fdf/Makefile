# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 14:26:54 by mszczesn          #+#    #+#              #
#    Updated: 2016/05/23 20:06:41 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CFLAGS += -Wall -Werror -Wextra -g

SRC =  main.c parser.c draw.c iso.c key.c

HEADER = fdf.h

OBJ = $(patsubst %.c,%.o, $(SRC))

.SILENT:

$(NAME): $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	make -C libft/
	$(CC) $(WFLAGS) -o $(NAME) $(OBJ) -L ft_printf/ -L libft/ -lft -lftprintf -lmlx -framework OpenGL -framework AppKit
	@echo "\033[0;32m     ___        __    ___  "
	@echo "\033[0;32m   .' ..]      |  ] .' ..] "
	@echo "\033[0;32m   _| |_   .--.| | _| |_   "
	@echo "\033[0;32m  '-| |-'/ /  \  |'-| |-'  "
	@echo "\033[0;32m    | |  | \__/  |  | |    "
	@echo "\033[0;32m   [___]  '.__. __][___]   "   
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
