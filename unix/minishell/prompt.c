/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:27:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/07 16:40:36 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
}

void	ft_freeenv(t_env *env)
{
	t_env *tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->result != NULL)
			free(tmp->result);
	}
}

int		ft_built(t_env *env, char **tab, char *str)
{
	int	i;

	i = 0;
	if ((ft_strcmp(tab[0], "cd") == 0) || (ft_strcmp(tab[0], "env") == 0) ||
	(ft_strcmp(tab[0], "unsetenv") == 0) || (ft_strcmp(tab[0], "setenv") == 0)
			|| (ft_strcmp(tab[0], "echo") == 0))
		i = 1;
	if (ft_strcmp(tab[0], "cd") == 0)
		ft_forcd(env, tab);
	if (ft_strcmp(tab[0], "env") == 0)
		ft_forenv(env, tab);
	if (ft_strcmp(tab[0], "unsetenv") == 0)
		env = ft_forunsetenv(env, tab);
	if (ft_strcmp(tab[0], "setenv") == 0)
		env = ft_forsetenv(env, tab);
	if (ft_strcmp(tab[0], "echo") == 0)
		ft_forecho(str);
	if (i == 1)
		return (1);
	return (0);
}

char	**ft_thepath(t_env *env)
{
	char **path;

	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
			path = ft_strsplit(env->result, ':');
		env = env->next;
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
}

char	*ft_checkpath(char **path, char **tab, char **tabenv)
{
	char	*path2;
	int		j;

	path2 = NULL;
	j = 0;
	while(path[j])
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
	return (path2);
}

char **ft_cmd(void)
{
	char **cmd;
	char *line;
	
	ft_printf("\033[032m$FuckingShell>\033[0m ");
	while (get_next_line(0, &line) == -1)
	{}
	cmd = ft_strsplit(line, ';');
	return (cmd);
}

void	ft_whileprompt(t_env *env, char **tabenv, char **path, char *path2)
{
	char **cmd;
	char **tab;
	pid_t pid;
	int i;
	
	while(42)
	{
		cmd = ft_cmd(); 
		i = 0;
		while(cmd[i])
		{
			tab = ft_strsplit(cmd[i], ' ');
			if (ft_built(env, tab, cmd[i]) == 1)
			{
				i++;
				continue;
			}
			if (ft_strcmp(tab[0], "exit") == 0)
			{
				ft_exit(tab, cmd, path, env);
				kill(pid, 0);
				exit(0);
			}	
			else
			{
				pid = fork();
				if (pid == 0)
					path2 = ft_checkpath(path, tab, tabenv);
				else
					wait(&pid);
				free(path2);
				ft_free(tab);
				i++;
			}
		}
	} 	
}

void	ft_prompt(t_env *env, char **tabenv)
{
	char **path;
	char *path2;

	path2 = NULL;
	path = ft_thepath(env);
	ft_whileprompt(env, tabenv, path, path2);
}
