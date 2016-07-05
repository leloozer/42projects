/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:02:18 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/29 16:15:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_forcd(t_env *env, char **tab)
{
	char *new;
	char *path;
	char *home;
	char *oldpwd;
	t_env *tmp;
	
	tmp = env;
	while(env)
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
	if ((tab[1] == NULL) || (ft_strcmp(tab[1], "~") == 0))
		new = ft_strdup(home);
	free(home);
	if (ft_strcmp(tab[1], "-") == 0)
		new = ft_strdup(oldpwd);
	if ((tab[1] != NULL) && (ft_strcmp(tab[1], "~") != 0) && (ft_strcmp(tab[1], "-") != 0))
	{
		new = ft_strjoin(path, "/");
		new = ft_strjoin(new, tab[1]);
	}
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
		env = tmp;
	}
	ft_free(tab);	
}

void	ft_forenv(t_env *env, char **tab)
{
	t_env *tmp;

	tmp = env;
	ft_free(tab);
	while(env)
	{
		ft_printf("%s=%s\n", env->name, env->result);
		env = env->next;
	}
	env = tmp;
}

t_env	*ft_forsetenv(t_env *env, char **tab)
{
	t_env	*tmp;
	int		ici;
	char	*line;

	tmp = env;
	ici = 0;
	if (tab[1] == NULL)
	{
		ft_printf("\033[031msetenv: usage setenv [name] [value] [number]\033[0m\n");
		return (env);
	}
	while(env)
	{
		if ((ft_strcmp(env->name, tab[1]) == 0) && (ft_strcmp(tab[3], "0") != 0))
		{
			ici = 1;
			env->result = ft_strdup(tab[2]);
		}
		env = env->next;
	}
	if (ici == 0)
	{
		line = ft_strjoin(tab[1], "=");
		line = ft_strjoin(line, tab[2]);
		env = tmp;
		ft_pushback(env, line);
	}
	env = tmp;
	return (env);
}

t_env	*ft_forunsetenv(t_env *env, char **tab)
{
	t_env	*tmp;
	t_env	*tmp2;
	t_env	*tmp3;
	int		ici;

	tmp = env;
	ici = 0;
	if (tab[1] == NULL)
	{
		ft_printf("\033[031munsetenv: usage unsetenv [name]\033[0m\n");
		return (env);
	}
	while(env)
	{
		if ((ft_strcmp(env->name, tab[1]) == 0))
		{	
			ici = 1;
			tmp2 = env;
		}
		env = env->next;
	}
	if (ici == 1)
	{
		tmp3 = tmp2->prev;
		tmp3->next = tmp2->next;
		free(tmp2->name);
		free(tmp2->result);
		free(tmp2->prev);
	}
	env = tmp;
	return (env);
}

void	ft_forecho(char *line)
{
	int		i;
	int		space;
	
	i = 0;
	space = 0;
	while(line[i] != 'o')
	{
		i++;
	}
	i++;
	while(line[i])
	{
		while (line[i] == '"' || line[i] == '\'' || line[i] == ' ')
		{
			if (line[i] == ' ')
				space = 1;
			i++;
		}
		if (space == 1)
		{
			ft_printf(" ");
			space = 0;
		}
		ft_printf("%c", line[i++]);
	}
	ft_printf("\n");
	free(line);
}
