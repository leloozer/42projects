/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 09:41:57 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 23:02:48 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initopt(t_option *opt)
{
	opt->l = 0;
	opt->maj_r = 0;
	opt->maj_s = 0;
	opt->a = 0;
	opt->r = 0;
	opt->u = 0;
	opt->p = 0;
	opt->t = 0;
	opt->c = 0;
	opt->file = 0;
	opt->block = 0;
	opt->lensize = 0;
	opt->lenlink = 0;
	opt->lenuid = 0;
	opt->finishopt = 0;
	opt->space = 0;
}

void	ft_initoptr(t_option *opt)
{
	opt->block = 0;
	opt->lensize = 0;
	opt->lenlink = 0;
	opt->lenuid = 0;
}

void	ft_initfile(t_file *file)
{
	file->dirr = 0;
	file->mode = NULL;
	file->nlink = 0;
	file->major = 0;
	file->minor = 0;
	file->uid = NULL;
	file->gid = NULL;
	file->size = 0;
	file->symlink = NULL;
	file->timer = NULL;
	file->time = NULL;
	file->name = NULL;
	file->path = NULL;
	file->fortime = 0;
	file->nsec = 0;
	file->next = NULL;
	file->prev = NULL;
}

void	ft_initforcheck(t_forcheck *check)
{
	check->name = NULL;
	check->path = NULL;
	check->dir = 0;
	check->next = NULL;
}

int		main(int argc, char **argv)
{
	t_option	*opt;
	t_forcheck	*check;
	t_file		*list;

	if ((opt = (t_option *)malloc(sizeof(t_option))) == NULL)
		return (0);
	if ((check = (t_forcheck *)malloc(sizeof(t_forcheck))) == NULL)
		return (0);
	if ((list = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (0);
	ft_initopt(opt);
	ft_initforcheck(check);
	ft_initfile(list);
	check = ft_parse(argc, argv, opt, check);
	ft_opendir(opt, check, list);
	ft_freeoption(opt);
	ft_freelist(list);
	return (0);
}
