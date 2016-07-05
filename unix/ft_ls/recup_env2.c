/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 11:56:20 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 14:06:02 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_stickybits(mode_t mode, char *str)
{
	if (mode & S_ISUID)
		str[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		str[6] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		str[9] = (mode & S_IXUSR) ? 't' : 'T';
	return (str);
}

char	*ft_typefile(mode_t mode)
{
	char *str;

	str = NULL;
	str = ft_strdup("----------");
	if (S_ISDIR(mode))
		str[0] = 'd';
	else if (S_ISREG(mode))
		str[0] = '-';
	else if (S_ISLNK(mode))
		str[0] = 'l';
	else if (S_ISCHR(mode))
		str[0] = 'c';
	else if (S_ISBLK(mode))
		str[0] = 'b';
	else if (S_ISFIFO(mode))
		str[0] = 'p';
	else if (S_ISSOCK(mode))
		str[0] = 's';
	str = ft_usrfile(mode, str);
	return (str);
}

char	*ft_usrfile(mode_t mode, char *str)
{
	if (mode & S_IRUSR)
		str[1] = 'r';
	if (mode & S_IWUSR)
		str[2] = 'w';
	if (mode & S_IXUSR)
		str[3] = 'x';
	if (mode & S_IRGRP)
		str[4] = 'r';
	if (mode & S_IWGRP)
		str[5] = 'w';
	if (mode & S_IXGRP)
		str[6] = 'x';
	if (mode & S_IROTH)
		str[7] = 'r';
	if (mode & S_IWOTH)
		str[8] = 'w';
	if (mode & S_IXOTH)
		str[9] = 'x';
	str = ft_stickybits(mode, str);
	return (str);
}

char	*ft_timefile(t_file *new, struct stat info)
{
	char	*timing;
	int		daylen;
	time_t	t;

	t = time(NULL);
	daylen = 0;
	daylen = ft_strlen(new->time[2]);
	if (daylen == 1)
		timing = ft_strjoin(new->time[1], "  ");
	if (daylen == 2)
		timing = ft_strjoin(new->time[1], " ");
	timing = ft_strjoin(timing, new->time[2]);
	new->time[3][5] = '\0';
	new->time[4][4] = '\0';
	if (info.st_mtime - t < -15778800 || info.st_mtime - t > 0)
	{
		timing = ft_strjoin(timing, "  ");
		timing = ft_strjoin(timing, new->time[4]);
	}
	else
	{
		timing = ft_strjoin(timing, " ");
		timing = ft_strjoin(timing, new->time[3]);
	}
	return (timing);
}

void	ft_lenlist(t_option *opt, t_file *new)
{
	int				sizelen;
	int				linklen;
	int				uidlen;

	uidlen = 0;
	if (new->uid != NULL)
		uidlen = ft_strlen(new->uid);
	if (uidlen > opt->lenuid)
		opt->lenuid = uidlen;
	linklen = ft_intlen(new->nlink);
	if (linklen > opt->lenlink)
		opt->lenlink = linklen;
	sizelen = ft_intlen(new->size);
	if (sizelen > opt->lensize)
		opt->lensize = sizelen;
}
