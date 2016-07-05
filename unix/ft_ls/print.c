/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:29:46 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 15:23:32 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlistl3(t_option *opt, t_file *list, int size)
{
	while (size < opt->lensize)
	{
		ft_printf(" ");
		size++;
	}
	ft_printf("%d %s %s", list->size, list->timer, list->name);
	if (opt->p == 1 && list->mode[0] == 'd')
		ft_printf("/");
	if (list->symlink != NULL)
		ft_printf(" -> %s\n", list->symlink);
	if (list->symlink == NULL)
		ft_printf("\n");
}

void	ft_printlistl2(t_option *opt, t_file *list)
{
	int		size;
	int		nlink;
	int		uidlen;

	uidlen = 0;
	ft_printf("%s  ", list->mode);
	nlink = ft_intlen(list->nlink);
	while (nlink < opt->lenlink)
	{
		ft_printf(" ");
		nlink++;
	}
	ft_printf("%d ", list->nlink);
	if (list->uid != NULL)
		uidlen = ft_strlen(list->uid);
	ft_printf("%s  ", list->uid);
	while (uidlen < opt->lenuid)
	{
		ft_printf(" ");
		uidlen++;
	}
	ft_printf("%s  ", list->gid);
	size = ft_intlen(list->size);
	ft_printlistl3(opt, list, size);
}

void	ft_printlistl(t_option *opt, t_file *list)
{
	t_file	*tmp;

	tmp = list;
	if (opt->l == 1)
	{
		while (list->next != NULL)
		{
			if (list->mode[0] == 'b' || list->mode[0] == 'c')
			{
				ft_printf("%s %d %s % 4s % 6d, %d %s %s\n", list->mode,
						list->nlink, list->uid, list->gid, list->major,
						list->minor, list->timer, list->name);
			}
			else
			{
				ft_printlistl2(opt, list);
			}
			list = list->next;
		}
		if (opt->t == 0 && opt->maj_s == 0)
			ft_printfinal(opt, list);
	}
	list = tmp;
}

void	ft_printfinal(t_option *opt, t_file *list)
{
	if (list->mode[0] == 'b' || list->mode[0] == 'c')
	{
		ft_printf("%s  %d %s % 4s % 6d, %d %s %s\n", list->mode, list->nlink,
				list->uid, list->gid, list->major, list->minor, list->timer,
				list->name);
	}
	else
	{
		if (list->uid == NULL)
		{
			write(2, "ls: ", 4);
			write(2, list->name, ft_strlen(list->name));
			ft_putendl_fd(": No such file or directory", 2);
			return ;
		}
		ft_printlistl2(opt, list);
	}
}

void	ft_printlistnotl(t_option *opt, t_file *list)
{
	t_file	*tmp;

	tmp = list;
	while (list->next != NULL)
	{
		ft_printf("%s", list->name);
		if (opt->p == 1 && list->mode[0] == 'd')
			ft_printf("/");
		ft_printf("\n");
		list = list->next;
	}
	if (opt->t == 0 && opt->maj_s == 0)
	{
		ft_printf("%s", list->name);
		if (opt->p == 1 && list->mode[0] == 'd')
			ft_printf("/");
		ft_printf("\n");
	}
	list = tmp;
}
