/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:58:06 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/16 18:52:02 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_finish(t_piece **piece)
{
	if (*piece)
		ft_freepiece(*piece);
	return (1);
}

void	ft_freepiece(t_piece *piece)
{
	if (piece->next)
		ft_freepiece(piece->next);
	free(piece);
	piece = NULL;
}



int	main(int argc, char **argv)
{
	if (argc != 2 || ft_openfile(argv[1]))
		write (1, "error\n", 6);
	return (0);
}
