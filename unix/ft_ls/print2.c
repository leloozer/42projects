/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:39:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 23:12:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printtotal(t_option *opt, t_file *list)
{
	if (list)
		ft_printf("total %d\n", opt->block);
}

void		ft_printfile2(t_option *opt, t_file *tmp)
{
	if (tmp->symlink == NULL)
		ft_printf("%s  %d %s  %s  %d %s %s", tmp->mode, tmp->nlink,
				tmp->uid, tmp->gid, tmp->size, tmp->timer, tmp->name);
	if (opt->p == 1 && tmp->mode[0] == 'd')
		ft_printf("/");
	ft_printf("\n");
	if (tmp->symlink != NULL)
		ft_printf("%s  %d %s  %s  %d %s %s -> %s\n", tmp->mode,
				tmp->nlink, tmp->uid, tmp->gid, tmp->size, tmp->timer,
				tmp->name, tmp->symlink);
}

void		ft_printfile(t_option *opt, t_file *tmp)
{
	if (opt->l == 0)
	{
		if (ft_strcmp("d---------", tmp->mode) == 0)
			ft_printf("./%s:\n", tmp->name);
		else
			ft_printf("%s\n", tmp->name);
	}
	else if (opt->l == 1)
	{
		if (tmp->mode[0] == 'b' || tmp->mode[0] == 'c')
		{
			ft_printf("%s  %d %s  %s %d, %d %s %s\n", tmp->mode, tmp->nlink,
					tmp->uid, tmp->gid, tmp->major, tmp->minor, tmp->timer,
					tmp->name);
		}
		else
			ft_printfile2(opt, tmp);
	}
}

t_forcheck	*ft_parse(int argc, char **argv, t_option *opt, t_forcheck *check)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && (ft_strcmp(argv[i], "--") != 0) &&
			(ft_strcmp(argv[i], "---") != 0) && (ft_strcmp(argv[i], "-") != 0))
		ft_checkopt(argv[i++], opt);
	if (ft_strcmp(argv[i], "--") == 0)
	{
		opt->finishopt = 1;
		i++;
	}
	if (i < argc)
		check = ft_checkfile(argv, opt, check, i);
	if (opt->file == 0)
	{
		check->name = ft_strdup(".");
		check->path = ft_strdup(".");
	}
	return (check);
}
