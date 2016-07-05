/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/10 16:28:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_file(char *path)
{
	int fd;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

int		is_nbr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		is_p_num(char *s)
{
	int		i;

	i = 0;
	if (!is_nbr(s))
		return (0);
	i = ft_atoi(s);
	return (i > 0 && i <= MAX_PLAYERS);
}

void	check_errors_args(int ac, char **argv, int *players)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(argv[i], "-dump") && i < ac - 1 && !is_nbr(argv[i + 1]))
			ft_error("Error : usage : invalid argument for -dump");
		if (!ft_strcmp(argv[i], "-n") && i < ac - 2
			&& !is_p_num(argv[i + 1]) && is_file(argv[i + 2]))
			ft_error("Error : usage : invalid argument for -n");
		if (!ft_strcmp(argv[i], "-dump"))
			i++;
		else if (!ft_strcmp(argv[i], "-v"))
			;
		else if (!ft_strcmp(argv[i], "-n"))
		{
			*players += 1;
			i += 2;
		}
		else if (!is_file(argv[i]))
			ft_error2("Error : can't read source file ", argv[i]);
		else
			*players += 1;
		i++;
	}
}

void	check_errors(int argc, char **argv)
{
	int		players;

	players = 0;
	if (argc <= 1)
		ft_error("Error : no arguments");
	check_errors_args(argc, argv, &players);
	if (players > MAX_PLAYERS || !players)
		ft_error("Error : wrong number of players");
}
