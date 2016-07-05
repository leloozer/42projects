/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 09:44:08 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 23:12:50 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_checkdir(char *str, t_file *check, t_option *opt)
{
	t_file	*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	ft_initfile(new);
	new->name = ft_strdup(str);
	new->path = ft_strdup(str);
	new->dirr = 1;
	if (check->name == NULL)
	{
		check->name = ft_strdup(str);
		check->path = ft_strdup(str);
		check->dirr = 1;
		return (check);
	}
	else
		check = ft_forfile(opt, new->name, new->path, check);
	return (check);
}

t_file		*ft_checkf(char *str, t_file *check, t_option *opt)
{
	t_file	*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	ft_initfile(new);
	new->name = ft_strdup(str);
	new->path = ft_strdup(str);
	if (check->name == NULL)
	{
		check->name = ft_strdup(str);
		check->path = ft_strdup(str);
		return (check);
	}
	else
		check = ft_forfile(opt, new->name, new->path, check);
	return (check);
}

t_forcheck	*ft_fusion2(t_file *checkdir, t_forcheck *check)
{
	t_forcheck *new;

	while (checkdir->name != NULL)
	{
		new = (t_forcheck *)malloc(sizeof(t_forcheck));
		ft_initforcheck(new);
		new->name = ft_strdup(checkdir->name);
		new->path = ft_strdup(checkdir->name);
		new->dir = 1;
		check->next = new;
		check = check->next;
		if (checkdir->next != NULL)
			checkdir = checkdir->next;
		else
			break ;
	}
	return (check);
}

t_forcheck	*ft_fusion(t_file *checkf, t_file *checkdir, t_forcheck *check)
{
	t_forcheck *new;
	t_forcheck *tmp;

	tmp = check;
	while (checkf->name != NULL)
	{
		new = (t_forcheck *)malloc(sizeof(t_forcheck));
		ft_initforcheck(new);
		new->name = ft_strdup(checkf->name);
		new->path = ft_strdup(checkf->name);
		new->dir = 0;
		check->next = new;
		check = check->next;
		if (checkf->next != NULL)
			checkf = checkf->next;
		else
			break ;
	}
	check = ft_fusion2(checkdir, check);
	check = tmp;
	check = check->next;
	return (check);
}

t_forcheck	*ft_checkfile(char **argv, t_option *opt, t_forcheck *check, int i)
{
	t_file		*checkdir;
	t_file		*checkf;
	struct stat	info;

	if ((checkdir = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	ft_initfile(checkdir);
	if ((checkf = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	ft_initfile(checkf);
	while (argv[i])
	{
		opt->file = opt->file + 1;
		if (lstat(argv[i], &info) == -1)
			ft_error(argv[i], 1);
		else if (opendir(argv[i]) == NULL)
			checkf = ft_checkf(argv[i], checkf, opt);
		else if (opendir(argv[i]) != NULL)
			checkdir = ft_checkdir(argv[i], checkdir, opt);
		i++;
	}
	check = ft_fusion(checkf, checkdir, check);
	ft_freelist(checkf);
	ft_freelist(checkdir);
	return (check);
}
