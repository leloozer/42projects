/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:23:30 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/29 16:15:41 by mszczesn         ###   ########.fr       */
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

typedef struct s_env
{
	char *name;
	char *result;
	struct s_env *next;
	struct s_env *prev;
}	t_env;

// main.c

void	ft_free(char **tab);
void	ft_pushback(t_env *env, char *line);
void	ft_firstpushback(t_env *env, char *line);

// prompt.c

void	ft_prompt(t_env *env, char **tabenv);

// builtin.c

void	ft_forcd(t_env *env, char **tab);
void	ft_forenv(t_env *env, char **tab);
void	ft_forecho(char *line);
t_env	*ft_forsetenv(t_env *env, char **tab);
t_env	*ft_forunsetenv(t_env *env, char **tab);

// function.c

char **ft_envtab(t_env *env);

#endif
