# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:46:46 by mszczesn          #+#    #+#              #
#    Updated: 2016/02/09 14:12:27 by mszczesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS += -Wall -Werror -Wextra

SRC = ft_printf.c\
	 check.c check2.c flag.c modificator.c modificator2.c \
	checkint.c ft_checkint2.c checkchar.c checkstr.c checkx.c checku.c checku2.c \
	checko.c \
	checkp.c checkcsmaj.c \
	ft_putnbr.c ft_putchar.c ft_putstr.c ft_strlen.c ft_lltoa_base.c \
	ft_putwchar.c \
	ft_lltoa_basemaj.c ft_ulltoa_base.c ft_ulltoa_basemaj.c ft_putnbruint.c \
	ft_ultoa_base.c ft_ultoa_basemaj.c

HEADER = printf.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar r $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		gcc $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
