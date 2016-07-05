/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 09:43:39 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 22:17:52 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_forcheck	*ft_freecheck(t_forcheck *check)
{
	free(check->name);
	free(check->path);
	check = check->next;
	return (check);
}

t_forcheck	*ft_openfile(t_option *opt, t_forcheck *check)
{
	t_file *list;

	list = (t_file *)malloc(sizeof(t_file));
	ft_initfile(list);
	while (check && check->dir == 0)
	{
		list = ft_forfile(opt, check->name, check->path, list);
		check = ft_freecheck(check);
	}
	if (opt->l == 1 && list->name != NULL)
	{
		ft_printlistl(opt, list);
	}
	else if (opt->l == 0 && list->name != NULL)
		ft_printlistnotl(opt, list);
	list = ft_freelist(list);
	return (check);
}

t_forcheck	*ft_printall(t_forcheck *tmpcheck, t_file *list, t_option *opt,
		t_forcheck *check)
{
	t_file			*tmp2;

	tmp2 = list;
	while (list)
	{
		if ((ft_strcmp(".", list->name) != 0) &&
				(ft_strcmp("..", list->name) != 0) &&
				opt->maj_r == 1 && list->mode[0] == 'd')
			tmpcheck = ft_checkadddir(tmpcheck, list->name, list->path);
		list = list->next;
	}
	list = tmp2;
	if (((opt->file > 1) || (opt->maj_r == 1)) &&
			(opt->space > 0 || opt->file > 1))
		ft_printf("%s:\n", check->path);
	if (opt->l == 1 && list->name != NULL)
	{
		ft_printtotal(opt, list);
		ft_printlistl(opt, list);
	}
	else if (opt->l == 0 && list->name != NULL)
		ft_printlistnotl(opt, list);
	return (tmpcheck);
}

t_forcheck	*ft_opendirif(t_forcheck *tmpcheck, t_file *list,
		t_option *opt, t_forcheck *check)
{
	DIR				*dir;
	struct dirent	*entry;

	if ((dir = opendir(check->path)) == NULL)
	{
		list = ft_forfile(opt, check->name, check->path, list);
		ft_printfile(opt, list);
	}
	else
	{
		while ((entry = readdir(dir)) != NULL)
		{
			if (opt->a == 1 || entry->d_name[0] != '.')
				list = ft_fordir(opt, entry->d_name, check->path, list);
		}
		tmpcheck = ft_printall(tmpcheck, list, opt, check);
		closedir(dir);
	}
	list = ft_freelist(list);
	return (tmpcheck);
}

void		ft_opendir(t_option *opt, t_forcheck *check, t_file *list)
{
	t_forcheck		*tmpcheck;

	if (opt->file > 0)
		check = ft_openfile(opt, check);
	while (check)
	{
		(opt->space > 0) ? ft_putchar('\n') : 0;
		tmpcheck = (t_forcheck *)malloc(sizeof(t_forcheck));
		ft_initforcheck(tmpcheck);
		tmpcheck = ft_opendirif(tmpcheck, list, opt, check);
		check = ft_checkfinal(check, tmpcheck);
		check = ft_freecheck(check);
		ft_initoptr(opt);
		list = (t_file *)malloc(sizeof(t_file));
		ft_initfile(list);
		opt->space = opt->space + 1;
	}
}
