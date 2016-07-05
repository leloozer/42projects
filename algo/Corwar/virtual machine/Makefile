# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 15:06:14 by mszczesn          #+#    #+#              #
#    Updated: 2016/03/10 12:21:44 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc
CFLAGS += -Wall -Werror -Wextra
NFLAGS += -Wall -Werror -Wextra -lncurses

SRC =	call_op.c \
		call_op2.c \
		check_errors.c \
		corewar.c \
		data_to_hexa.c \
		exec_op.c \
		exec_op2.c \
		exec_op3.c \
		exec_op4.c \
		exec_op_fct.c \
		exec_op_fct2.c \
		get_env.c \
		get_env2.c \
		init.c \
		ncurses.c \
		ncurses2.c \
		ncurses_colors.c \
		op.c \
		run_vm.c \
		run_vm2.c \
		set_processes.c \
		set_vm.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(NFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "\033[0;32m[vm ready]\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
	@echo "\033[0;31m[vm deleted]\033[0m"

re: fclean all
