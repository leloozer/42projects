/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:19:27 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/03 16:43:27 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	int				tmp1;
	int				tmp2;
	t_elementlist	*tmp3;

	tmp3 = list_a->first;
	tmp1 = list_a->last->number;
	while (list_a->first != NULL)
	{
		tmp2 = list_a->first->number;
		list_a->first->number = tmp1;
		tmp1 = tmp2;
		list_a->first = list_a->first->next;
	}
	list_a->first = tmp3;
	write(1, " ra", 3);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int	ft_rb(t_reperelist *list_b, t_reperelist *list_a, t_option *opt)
{
	int				tmp1;
	int				tmp2;
	t_elementlist	*tmp3;

	tmp3 = list_b->first;
	tmp1 = list_b->last->number;
	while (list_b->first != NULL)
	{
		tmp2 = list_b->first->number;
		list_b->first->number = tmp1;
		tmp1 = tmp2;
		list_b->first = list_b->first->next;
	}
	list_b->first = tmp3;
	write(1, " rb", 3);
	opt->nbr++;
	if (opt->afflist == 1)
		ft_printlist(list_a, list_b);
	return (1);
}

int	ft_rr(t_reperelist *list_a, t_reperelist *list_b, t_option *opt)
{
	ft_ra(list_a, list_b, opt);
	ft_rb(list_b, list_a, opt);
	return (1);
}
