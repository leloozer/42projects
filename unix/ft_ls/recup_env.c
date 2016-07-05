/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:28:56 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 14:30:56 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_opttime(t_option *opt, t_file *new, struct stat info)
{
	if (opt->u == 0 && opt->c == 0)
		new->time = ft_strsplit(ctime(&info.st_mtimespec.tv_sec), ' ');
	if (opt->u == 1)
		new->time = ft_strsplit(ctime(&info.st_atimespec.tv_sec), ' ');
	if (opt->c == 1)
		new->time = ft_strsplit(ctime(&info.st_ctimespec.tv_sec), ' ');
}

void	ft_modespe(t_file *new, struct stat info, t_option *opt)
{
	char			buf[100];

	if (new->mode[0] == 'c' || new->mode[0] == 'b')
	{
		new->major = major(info.st_rdev);
		new->minor = minor(info.st_rdev);
	}
	if (new->mode[0] == 'l')
	{
		readlink(new->path, buf, 100);
		new->symlink = ft_strdup(buf);
	}
	if (opt->u == 0 && opt->c == 0)
		new->fortime = (int)info.st_mtime;
	if (opt->u == 1)
		new->fortime = (int)info.st_atime;
	if (opt->c == 1)
		new->fortime = (int)info.st_ctime;
}

void	ft_info(struct passwd *pw, struct group *gr,
		struct stat info, t_file *new)
{
	new->mode = ft_typefile(info.st_mode);
	new->nlink = (int)info.st_nlink;
	new->uid = pw ? ft_strdup(pw->pw_name) : NULL;
	new->gid = gr ? ft_strdup(gr->gr_name) : NULL;
	new->size = (int)info.st_size;
	new->timer = ft_timefile(new, info);
	new->next = NULL;
}

t_file	*ft_forfile(t_option *opt, char *name, char *path, t_file *list)
{
	struct stat		info;
	struct passwd	*pw;
	struct group	*gr;
	t_file			*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	ft_initfile(new);
	lstat(path, &info);
	pw = getpwuid(info.st_uid);
	gr = getgrgid(info.st_gid);
	ft_opttime(opt, new, info);
	ft_info(pw, gr, info, new);
	ft_modespe(new, info, opt);
	new->name = ft_strdup(name);
	new->nsec = info.st_mtimespec.tv_nsec;
	ft_lenlist(opt, new);
	list = ft_sortfile(opt, new, list);
	return (list);
}

t_file	*ft_fordir(t_option *opt, char *name, char *path, t_file *list)
{
	struct stat		info;
	struct passwd	*pw;
	struct group	*gr;
	t_file			*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	ft_initfile(new);
	new->path = ft_strjoin(path, "/");
	new->path = ft_strjoin(new->path, name);
	lstat(new->path, &info);
	opt->block = opt->block + info.st_blocks;
	pw = getpwuid(info.st_uid);
	gr = getgrgid(info.st_gid);
	ft_opttime(opt, new, info);
	ft_info(pw, gr, info, new);
	ft_modespe(new, info, opt);
	ft_lenlist(opt, new);
	new->nsec = info.st_mtimespec.tv_nsec;
	new->name = ft_strdup(name);
	list = ft_sortfile(opt, new, list);
	return (list);
}
