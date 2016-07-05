/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:52:14 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 16:02:59 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_forcheck	*ft_checkadddir(t_forcheck *tmpcheck, char *name, char *path)
{
	t_forcheck *ptfirst;
	t_forcheck *new;

	if (tmpcheck && tmpcheck->name != NULL)
		ptfirst = tmpcheck;
	if ((new = (t_forcheck *)malloc(sizeof(t_forcheck))) == NULL)
		return (NULL);
	ft_initforcheck(new);
	new->name = ft_strdup(name);
	new->path = ft_strdup(path);
	if (tmpcheck->name == NULL)
		tmpcheck = new;
	else
	{
		while (tmpcheck->next)
			tmpcheck = tmpcheck->next;
		new->next = tmpcheck->next;
		tmpcheck->next = new;
		tmpcheck = ptfirst;
	}
	return (tmpcheck);
}

t_forcheck	*ft_checkfinal(t_forcheck *check, t_forcheck *tmpcheck)
{
	t_forcheck *tmp;
	t_forcheck *ptfirst;

	ptfirst = check;
	if (tmpcheck->name == NULL)
		return (check);
	if (check->next == NULL)
		check->next = tmpcheck;
	else if (check->next != NULL)
	{
		tmp = check->next;
		check->next = tmpcheck;
		while (tmpcheck->next)
			tmpcheck = tmpcheck->next;
		tmpcheck->next = tmp;
	}
	check = ptfirst;
	return (check);
}
