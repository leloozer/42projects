/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:50:07 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 22:56:38 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf/printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>

typedef struct			s_option
{
	int					l;
	int					maj_r;
	int					maj_s;
	int					a;
	int					c;
	int					r;
	int					p;
	int					t;
	int					u;
	unsigned long		block;
	int					file;
	int					lensize;
	int					lenlink;
	int					lenuid;
	int					finishopt;
	int					space;
}						t_option;

typedef struct			s_file
{
	char				*mode;
	int					dirr;
	int					nlink;
	unsigned int		major;
	unsigned int		minor;
	char				*uid;
	char				*gid;
	int					size;
	char				*symlink;
	char				*timer;
	char				**time;
	char				*name;
	char				*path;
	unsigned long		fortime;
	long				nsec;
	struct s_file		*next;
	struct s_file		*prev;
}						t_file;

typedef	struct			s_forcheck
{
	char				*name;
	char				*path;
	int					dir;
	struct s_forcheck	*next;
}						t_forcheck;

void					ft_initopt(t_option *opt);
void					ft_initoptr(t_option *opt);
void					ft_initfile(t_file *file);
void					ft_initforcheck(t_forcheck *check);

t_forcheck				*ft_parse(int argc, char **argv, t_option *opt,
						t_forcheck *check);
void					ft_checkopt(char *str, t_option *opt);
t_forcheck				*ft_checkfile(char **argv, t_option *opt,
						t_forcheck *check, int i);

void					ft_opendir(t_option *opt, t_forcheck *check,
						t_file *list);
t_forcheck				*ft_checkadddir(t_forcheck *tmpcheck, char *name,
						char *path);
t_forcheck				*ft_checkfinal(t_forcheck *check, t_forcheck *tmpcheck);

char					*ft_typefile(mode_t mode);
char					*ft_usrfile(mode_t mode, char *str);
t_file					*ft_fordir(t_option *opt, char *name, char *path,
						t_file *list);
t_file					*ft_forfile(t_option *opt, char *name, char *pathi,
						t_file *list);

char					*ft_stickybits(mode_t mode, char *str);
char					*ft_timefile(t_file *new, struct stat info);
void					ft_lenlist(t_option *opt, t_file *new);

t_forcheck				*ft_sortcheck(t_forcheck *new, t_forcheck *check,
						t_option *opt);
t_file					*ft_sortfile(t_option *opt, t_file *new, t_file *list);
t_file					*ft_sortname(t_file *new, t_file *list);
t_file					*ft_sortnamerev(t_file *new, t_file *list);
t_file					*ft_sorttime(t_file *new, t_file *list);
t_file					*ft_sorttimerev(t_file *new, t_file *list);

t_file					*ft_sortsize(t_file *new, t_file *list);
t_file					*ft_sortsizerev(t_file *new, t_file *list);
t_file					*ft_insertlist(t_file *list, t_file *new);
t_file					*ft_pushfront(t_file *new, t_file *list);

void					ft_printlistl(t_option *opt, t_file *list);
void					ft_printlistnotl(t_option *opt, t_file *list);
void					ft_printfinal(t_option *opt, t_file *list);
void					ft_printtotal(t_option *opt, t_file *list);
void					ft_printfile(t_option *opt, t_file *tmp);

void					ft_freeoption(t_option *opt);
t_file					*ft_freelist(t_file *list);
void					ft_freeforcheck(t_forcheck *check);
void					ft_error(char *str, int i);

int						ft_intlen(int nbr);
char					**ft_strsplit(char const *s, char c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s1);
void					ft_putendl_fd(char const *s, int fd);

#endif
