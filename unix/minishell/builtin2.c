/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:12:26 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/20 13:35:11 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_printspace(void)
{
	ft_printf(" ");
	return (0);
}

void	ft_forecho(char *line, t_env *env)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (line[i - 1] != 'o')
		i++;
	i++;
	while (line[i])
	{
		while (line[i] == '"' || line[i] == '\0' || line[i] == ' ')
		{
			if (line[i] == ' ')
				space = 1;
			i++;
		}
		if (space == 1)
			space = ft_printspace();
		if (line[i] == '$' && (line[i - 1] == ' ' || i == 0 ||
					line[i - 1] == '"'))
			i = ft_echoenv(line, i, env);
		ft_printf("%c", line[i++]);
	}
	ft_printf("\n");
	free(line);
}

void	ft_forcd3(char *new, t_env *env, char *path, char **tab)
{
	if (chdir(new) == -1)
		ft_printf("\033[031mcd : No such directory: %s\033[0m\n", tab[1]);
	if (chdir(new) != -1)
	{
		while (env)
		{
			if (ft_strcmp(env->name, "PWD") == 0)
				env->result = ft_strdup(new);
			if (ft_strcmp(env->name, "OLDPWD") == 0)
				env->result = ft_strdup(path);
			env = env->next;
		}
	}
}

char	*ft_forcd2(char *home, char *path, char *oldpwd, char **tab)
{
	char	*new;

	new = NULL;
	if (path == NULL || home == NULL || oldpwd == NULL)
	{
		ft_printf("\033[031mERROR ENV\033[0m\n");
		exit(0);
	}
	if (tab[1] == NULL)
		new = ft_strdup(home);
	else if (ft_strcmp(tab[1], "~") == 0)
		new = ft_strdup(home);
	else if (ft_strcmp(tab[1], "-") == 0)
		new = ft_strdup(oldpwd);
	else if ((tab[1] != NULL) && (ft_strcmp(tab[1], "~") != 0) &&
			(ft_strcmp(tab[1], "-") != 0))
	{
		if (chdir(tab[1]) != -1)
			return (tab[1]);
		new = ft_strjoin(path, "/");
		new = ft_strjoin(new, tab[1]);
	}
	return (new);
}

void	ft_forcd(t_env *env, char **tab)
{
	char	*path;
	char	*home;
	char	*oldpwd;
	char	*new;
	t_env	*tmp;

	tmp = env;
	path = NULL;
	home = NULL;
	oldpwd = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, "PWD") == 0)
			path = env->result;
		if (ft_strcmp(env->name, "HOME") == 0)
			home = ft_strdup(env->result);
		if (ft_strcmp(env->name, "OLDPWD") == 0)
			oldpwd = ft_strdup(env->result);
		env = env->next;
	}
	env = tmp;
	new = ft_forcd2(home, path, oldpwd, tab);
	ft_forcd3(new, env, path, tab);
}
