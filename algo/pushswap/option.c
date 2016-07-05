/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:45:28 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/03 17:01:10 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkoption(char **argv, t_option *opt)
{
	int	j;

	j = 1;
	opt->afflist = 0;
	opt->nbr = 0;
	if (argv[1][0] != '-')
		return (1);
	while (argv[1][j])
	{
		if (argv[1][j] == 'v')
			opt->afflist = 1;
		if (argv[1][j] == 'n')
			opt->nbr = 1;
		if ((argv[1][j]) != 'v' && argv[1][j] != 'n')
		{
			opt->afflist = 0;
			opt->nbr = 0;
			return (1);
		}
		j++;
	}
	return (2);
}
