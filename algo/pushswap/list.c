/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:33:34 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/10 22:19:53 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_error(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j + i])
		{
			if (ft_strcmp(argv[i], argv[j + i]) == 0)
				return (-1);
			if ((ft_strcmp(argv[i], "0") == 0) &&
					(ft_strcmp(argv[j + i], "-0") == 0))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_firstelemlist(t_reperelist *list_a, char *argv)
{
	t_elementlist	*new;

	if ((new = (t_elementlist*)malloc(sizeof(t_elementlist))) == NULL)
		return (-1);
	else
	{
		new->number = ft_atoi(argv);
		new->prev = list_a->first;
		new->next = list_a->last;
		list_a->first = new;
		list_a->last = new;
		list_a->last->next = NULL;
		list_a->len++;
	}
	return (0);
}

int				ft_pushfront(t_reperelist *list_a, char *argv)
{
	t_elementlist	*new;

	if ((new = (t_elementlist*)malloc(sizeof(t_elementlist))) == NULL)
		return (-1);
	else
	{
		new->number = ft_atoi(argv);
		new->next = list_a->first;
		new->prev = NULL;
		list_a->first->prev = new;
		list_a->first = new;
		list_a->len++;
	}
	return (0);
}

t_reperelist	*ft_initial(t_reperelist *list)
{
	list = (t_reperelist*)malloc(sizeof(t_reperelist));
	if (list != NULL)
	{
		list->len = 0;
		list->first = NULL;
		list->last = NULL;
	}
	return (list);
}

int				ft_listinit(int argc, char **argv, t_option *opt)
{
	t_reperelist	*list_a;
	t_reperelist	*list_b;
	int				i;

	i = ft_checkoption(argv, opt);
	list_a = NULL;
	list_b = NULL;
	if (((list_a = ft_initial(list_a)) == NULL) ||
			((list_b = ft_initial(list_b)) == NULL))
		return (-1);
	if ((ft_error(argv) == -1) || (ft_errornotint(argv, opt) == -1)
		|| (ft_notint(argv, opt) == -1))
		return (-1);
	else
	{
		ft_firstelemlist(list_a, argv[i]);
		i++;
		while (i < argc)
		{
			ft_pushfront(list_a, argv[i]);
			i++;
		}
		ft_opt(list_a, list_b, opt);
	}
	return (0);
}
