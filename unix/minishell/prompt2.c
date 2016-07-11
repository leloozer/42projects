/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 11:51:55 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/11 15:50:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_built(char **tab)
{
	if ((ft_strcmp(tab[0], "cd") == 0) || (ft_strcmp(tab[0], "env") == 0) ||
	(ft_strcmp(tab[0], "unsetenv") == 0) || (ft_strcmp(tab[0], "setenv") == 0)
			|| (ft_strcmp(tab[0], "echo") == 0))
		return (1);
	else
		return (0);
}

t_env	*ft_gobuilt(t_env *env, char **tab, char *str)
{
	if (ft_strcmp(tab[0], "unsetenv") == 0)
		env = ft_forunsetenv(env, tab);
	if (ft_strcmp(tab[0], "setenv") == 0)
		env = ft_forsetenv(env, tab);
	if (ft_strcmp(tab[0], "echo") == 0)
		ft_forecho(str);
	if (ft_strcmp(tab[0], "cd") == 0)
		ft_forcd(env, tab);
	if (ft_strcmp(tab[0], "env") == 0)
		ft_forenv(env);
	return (env);
}

char	**ft_thepath(t_env *env)
{
	char	**path;
	int		i;

	i = 0;
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
		{
			i = 1;
			path = ft_strsplit(env->result, ':');
		}
		env = env->next;
	}
	if (i == 0)
	{
		ft_printf("\033[031mNO SUCH PATH BYE !!!!!!\033[0m\n");
		exit(0);
	}
	return (path);
}

void	ft_exit(char **tab, char **cmd, char **path, t_env *env)
{
	if (tab != NULL)
		ft_free(tab);
	if (cmd != NULL)
		ft_free(cmd);
	if (path != NULL)
		ft_free(path);
	ft_freeenv(env);
	ft_printf("\033[033mCiao baby!\033[0m\n");
	exit(0);
}

char	*ft_checkpath(char **path, char **tab, char **tabenv)
{
	char	*path2;
	int		j;

	path2 = ft_strdup(tab[0]);
	j = 0;
	if (execve(path2, tab, tabenv) == -1)
	{
		while (path[j])
		{
			path2 = ft_strjoin(path[j], "/");
			path2 = ft_strjoin(path2, tab[0]);
			if (execve(path2, tab, tabenv) == -1)
			{
				free(path2);
				j++;
			}
		}
		if (execve(path2, tab, tabenv) == -1)
			ft_printf("\033[031mcommand not found: %s\033[0m\n", tab[0]);
		exit(0);
	}
	return (path2);
}
