/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:23:30 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/11 15:10:54 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_printf/printf.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>

typedef struct		s_env
{
	char			*name;
	char			*result;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

void				ft_free(char **tab);
void				ft_freeenv(t_env *env);
void				ft_pushback(t_env *env, char *line);
void				ft_firstpushback(t_env *env, char *line);

void				ft_prompt(t_env *env, char **tabenv);
int					ft_built(char **tab);
t_env				*ft_gobuilt(t_env *env, char **tab, char *str);
char				**ft_thepath(t_env *env);
void				ft_exit(char **tab, char **cmd, char **path, t_env *env);
char				*ft_checkpath(char **path, char **tab, char **tabenv);
char				**ft_envspe(char **tab);
void				ft_pushsetenv(t_env *env, char *str, char *str2);

void				ft_forcd(t_env *env, char **tab);
void				ft_forenv(t_env *env);
void				ft_forecho(char *line);
t_env				*ft_forsetenv(t_env *env, char **tab);
t_env				*ft_forunsetenv(t_env *env, char **tab);

char				**ft_envtab(t_env *env);

#endif
