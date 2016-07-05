/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:45:37 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/10 22:35:34 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_errornotint(char **argv, t_option *opt)
{
	int	i;
	int	j;

	if (opt->afflist == 0 && opt->nbr == 0)
		i = 1;
	else
		i = 2;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_algo2(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	while (ft_check2(list_b) != 1)
	{
		while ((list_b->last->number < list_b->last->prev->number)
				|| (list_b->first->number > list_b->first->next->number))
		{
			if (list_b->last->number < list_b->last->prev->number)
				ft_sb(list_b, list_a, opt);
			else
				ft_rrb(list_b, list_a, opt);
		}
		if (ft_check(list_b) != 1)
			ft_pa(list_a, list_b, opt);
	}
}

int		ft_notint(char **argv, t_option *opt)
{
	int	i;

	if (opt->afflist == 0 || opt->nbr == 0)
		i = 1;
	else
		i = 2;
	while (argv[i])
	{
		if ((ft_atoll(argv[i]) < -2147483648) ||
				(ft_atoll(argv[i]) > 2147483647))
			return (-1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_option	opt;

	if (argc <= 1)
		return (0);
	else
	{
		if (ft_listinit(argc, argv, &opt) == -1)
			write(1, "error\n", 6);
		else
			write(1, "\n", 1);
	}
	return (0);
}
