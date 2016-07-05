/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:01:40 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 23:12:31 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *str, int i)
{
	if (i == 1)
	{
		write(2, "ls: ", 4);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
}

void	ft_freeoption(t_option *opt)
{
	free(opt);
}

void	ft_freetime(char **str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

t_file	*ft_freelist(t_file *list)
{
	t_file	*tmp;
	t_file	*tmp2;

	tmp = list;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->mode);
		free(tmp2->uid);
		free(tmp2->gid);
		free(tmp2->timer);
		ft_freetime(tmp2->time);
		free(tmp2->name);
		free(tmp2->symlink);
		free(tmp2->path);
		free(tmp2);
	}
	list = tmp;
	return (list);
}

void	ft_freeforcheck(t_forcheck *check)
{
	t_forcheck	*tmp;
	t_forcheck	*tmp2;

	tmp = check;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->name);
		free(tmp2->path);
		free(tmp2);
	}
}
