/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:59:10 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/10 22:06:12 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	int				tmp;
	t_elementlist	*e1;
	t_elementlist	*e2;

	e1 = list_a->last;
	e2 = list_a->last->prev;
	if (e1 == NULL)
		return (-1);
	if (e2 == NULL)
		return (0);
	tmp = e1->number;
	e1->number = e2->number;
	e2->number = tmp;
	write(1, " sa", 3);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int	ft_sb(t_reperelist *list_b, t_reperelist *list_a, t_option *opt)
{
	int				tmp;
	t_elementlist	*e1;
	t_elementlist	*e2;

	e1 = list_b->last;
	e2 = list_b->last->prev;
	if (e1 == NULL)
		return (-1);
	if (e2 == NULL)
		return (0);
	tmp = e1->number;
	e1->number = e2->number;
	e2->number = tmp;
	write(1, " sb", 3);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int	ft_pa(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	t_elementlist	*tmp;

	if (list_a == NULL)
		return (-1);
	if (list_b == NULL)
		return (0);
	tmp = list_b->last;
	if (list_b->first == list_b->last)
	{
		list_b->first = NULL;
		list_b->last = NULL;
		list_a->last->next = tmp;
		tmp->prev = list_a->last;
		list_a->last = tmp;
		write(1, " pa", 3);
		opt->nbr++;
		if (opt->afflist == 1)
			ft_printlist(list_a, list_b);
		return (1);
	}
	ft_pa2(list_a, list_b, tmp, opt);
	return (1);
}

int	ft_pa2(t_reperelist *list_a, t_reperelist *list_b,
		t_elementlist *tmp, t_option *opt)
{
	if (list_b->last->prev != NULL)
	{
		list_b->last = list_b->last->prev;
		list_b->last->next = NULL;
	}
	if (list_b->last != NULL)
		list_b->last->next = NULL;
	tmp->next = NULL;
	if (list_a->last != NULL)
	{
		list_a->last->next = tmp;
		tmp->prev = list_a->last;
		list_a->last = tmp;
	}
	else
	{
		tmp->prev = NULL;
		list_a->first = tmp;
		list_a->last = tmp;
	}
	write(1, " pa", 3);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int	ft_pb(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	t_elementlist *tmp;

	if (list_b == NULL)
		return (-1);
	if (list_a == NULL)
		return (0);
	tmp = list_a->last;
	{
		list_a->last = list_a->last->prev;
		list_a->last->next = NULL;
	}
	if (list_a->first == list_a->last)
	{
		list_a->first = NULL;
		list_a->last = NULL;
	}
	if (list_a->last != NULL)
		list_a->last->next = NULL;
	tmp->next = NULL;
	ft_pb2(list_a, list_b, tmp, opt);
	return (1);
}
