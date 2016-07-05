/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:26:54 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/10 22:32:54 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_reperelist	*ft_algo(t_reperelist *list_a, t_reperelist *list_b,
						t_option *opt)
{
	while (ft_check(list_a) != 1)
	{
		while ((list_a->last->number > list_a->last->prev->number)
				|| (list_a->first->number < list_a->first->next->number))
		{
			if (list_a->last->number > list_a->last->prev->number)
				ft_sa(list_a, list_b, opt);
			else
				ft_rra(list_a, list_b, opt);
		}
		if (ft_check(list_a) != 1)
			ft_pb(list_a, list_b, opt);
	}
	ft_algo2(list_a, list_b, opt);
	if ((ft_check(list_a) == 1) && (ft_check2(list_b) == 1) &&
			(list_b->first != NULL))
	{
		while ((ft_check(list_a) == 1) && (ft_check2(list_b) == 1) &&
				(list_b->first->next != NULL))
			ft_pa(list_a, list_b, opt);
		ft_pa(list_a, list_b, opt);
	}
	if ((ft_check(list_a) || ft_check2(list_b)) != 1 || list_b->first != NULL)
		return (ft_algo(list_a, list_b, opt));
	return (list_a);
}

int				ft_check(t_reperelist *list_a)
{
	t_elementlist *tmp;

	tmp = list_a->first;
	while (list_a->first->next != NULL)
	{
		if (list_a->first->number < list_a->first->next->number)
		{
			list_a->first = tmp;
			return (0);
		}
		list_a->first = list_a->first->next;
	}
	list_a->first = tmp;
	return (1);
}

int				ft_check2(t_reperelist *list_b)
{
	t_elementlist *tmp;

	tmp = list_b->first;
	if (list_b->first == NULL)
		return (1);
	while (list_b->first->next != NULL)
	{
		if (list_b->first->number > list_b->first->next->number)
		{
			list_b->first = tmp;
			return (0);
		}
		list_b->first = list_b->first->next;
	}
	list_b->first = tmp;
	return (1);
}

int				ft_printlist(t_reperelist *list_a, t_reperelist *list_b)
{
	t_elementlist	*tmp;

	tmp = list_a->first;
	write(1, "\n", 1);
	write(1, "list_a: ", 8);
	while (list_a->first->next != NULL)
	{
		ft_putnbr(list_a->first->number);
		write(1, " ", 1);
		list_a->first = list_a->first->next;
	}
	ft_putnbr(list_a->first->number);
	list_a->first = tmp;
	write(1, "\n", 1);
	ft_printlist2(list_b);
	return (0);
}

int				ft_printlist2(t_reperelist *list_b)
{
	t_elementlist	*tmp2;

	tmp2 = list_b->first;
	write(1, "list_b: ", 8);
	if (list_b->first != NULL)
	{
		while (list_b->first->next != NULL)
		{
			ft_putnbr(list_b->first->number);
			write(1, " ", 1);
			list_b->first = list_b->first->next;
		}
		ft_putnbr(list_b->first->number);
		list_b->first = tmp2;
	}
	write(1, "\n", 1);
	return (0);
}
