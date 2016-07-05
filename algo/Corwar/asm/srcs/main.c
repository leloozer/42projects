/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:19:05 by mszczesn          #+#    #+#             */
/*   Updated: 2016/04/08 16:11:01 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_tlist	*ft_error(char *msg)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(0);
	return (NULL);
}

void	ft_errorandexit(int x)
{
	if (x == 1)
		ft_printf("\033[31musage: ./asm <name>.s\033[0m\n");
	else if (x == 2)
		ft_printf("\033[31mError fail file!!!!\033[0m\n");
	else if (x == 3)
		ft_printf("\033[31mBad Name\033[0m\n");
	else if (x == 4)
		ft_printf("\033[31mBad Commentary\033[0m\n");
	else if (x == 5)
		ft_printf("\033[31mBad OP Code\033[0m\n");
	else if (x == 7)
		ft_printf("\033[31mError File\033[0m\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_tlist		*token_list;
	t_file		*file;

	file = NULL;
	token_list = NULL;
	file = ft_initfile(file);
	if (argc != 2)
		ft_errorandexit(1);
	else
	{
		token_list = ft_lexer(argv[1], token_list, file);
		file = ft_createfile(file);
		file = ft_gotohexa(token_list, file);
	}
	return (0);
}
