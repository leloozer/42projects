/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:17:16 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/10 22:15:59 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rra(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	int				tmp1;
	int				tmp2;
	t_elementlist	*tmp3;

	tmp3 = list_a->last;
	tmp1 = list_a->first->number;
	while (list_a->last != NULL)
	{
		tmp2 = list_a->last->number;
		list_a->last->number = tmp1;
		tmp1 = tmp2;
		list_a->last = list_a->last->prev;
	}
	list_a->last = tmp3;
	write(1, " rra", 4);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int		ft_rrb(t_reperelist *list_b, t_reperelist *list_a, t_option *opt)
{
	int				tmp1;
	int				tmp2;
	t_elementlist	*tmp3;

	tmp3 = list_b->last;
	tmp1 = list_b->first->number;
	while (list_b->last != NULL)
	{
		tmp2 = list_b->last->number;
		list_b->last->number = tmp1;
		tmp1 = tmp2;
		list_b->last = list_b->last->prev;
	}
	list_b->last = tmp3;
	write(1, " rrb", 4);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int		ft_pb2(t_reperelist *list_a, t_reperelist *list_b,
		t_elementlist *tmp, t_option *opt)
{
	if (list_b->last != NULL)
	{
		list_b->last->next = tmp;
		tmp->prev = list_b->last;
		list_b->last = tmp;
	}
	else
	{
		tmp->prev = NULL;
		list_b->first = tmp;
		list_b->last = tmp;
	}
	write(1, " pb", 3);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

void	ft_opt(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	ft_algo(list_a, list_b, opt);
	if (opt->nbr != 0)
	{
		opt->nbr--;
		write(1, "\n", 1);
		write(1, "nombre d'operations: ", 21);
		ft_putnbr(opt->nbr);
	}
}
