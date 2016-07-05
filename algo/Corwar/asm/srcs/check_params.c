/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:59:36 by ndauteui          #+#    #+#             */
/*   Updated: 2016/03/28 18:45:48 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_match_types(int type)
{
	int		ret;

	ret = 0;
	if (type == PARAM_REG)
		return (ret |= T_REG);
	else if (type == PARAM_DIR || type == PARAM_LABEL_DIR)
		return (ret |= T_DIR);
	else if (type == PARAM_IND || type == PARAM_LABEL_IND)
		return (ret |= T_IND);
	return (0);
}

int		ft_get_args_nb(t_tlist *tmp)
{
	int		nb;
	t_tlist	*tmp2;

	tmp2 = tmp;
	nb = 0;
	while (tmp2->next && tmp2->type != INSTRUCTION
		&& tmp2->type != INSTRUCTION_SPE && tmp2->type != LABEL)
	{
		if (tmp2->type != ENDL && tmp2->type != LABEL)
			nb++;
		tmp2 = tmp2->next;
	}
	return (nb);
}

int		ft_check_after(t_tlist *tmp)
{
	t_op	*op;
	int		i;

	op = ft_get_op_by_name(tmp->content);
	tmp = tmp->next;
	if (ft_get_args_nb(tmp) != op->args_nb)
		return (0);
	i = 0;
	while (tmp->next && tmp->type != INSTRUCTION && tmp->type != INSTRUCTION_SPE
		&& tmp->type != LABEL)
	{
		if (tmp->type != LABEL && tmp->type != ENDL && !(op->args_type[i] &
			ft_match_types(tmp->type)))
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_check_params(t_tlist *tlist)
{
	t_tlist		*tmp;

	tmp = tlist;
	while (tmp->next)
	{
		if (tmp->type == INSTRUCTION || tmp->type == INSTRUCTION_SPE)
		{
			if (ft_check_after(tmp) == 0)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
