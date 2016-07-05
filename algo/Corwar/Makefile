#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 23:40:05 by ndauteui          #+#    #+#              #
#    Updated: 2016/04/06 23:45:47 by ndauteui         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lol

all: $(NAME)

$(NAME):
	make -C asm/
	make -C virtual\ machine/
	@cp asm/asm bin/asm
	@cp virtual\ machine/corewar bin/corewar

clean:
	make -C asm/ clean
	make -C virtual\ machine/ clean

fclean:
	@rm bin/asm
	@rm bin/corewar
	make -C asm/ fclean
	make -C virtual\ machine/ fclean

re:
	fclean all

.PHONY: re fclean clean all