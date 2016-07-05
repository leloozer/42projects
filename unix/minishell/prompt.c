/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:27:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/29 16:15:38 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **tab)
{
	int		i;

	i = 0;
	while(tab[i])
	{
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
}

void	ft_freeenv(t_env *env)
{
	t_env *tmp;

	while(env)
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
	if (ft_strcmp(tab[0], "cd") == 0)
	{
		ft_forcd(env, tab);
		return (1);
	}
	if (ft_strcmp(tab[0], "env") == 0)
	{
		ft_forenv(env, tab);
		return (1);
	}
	if (ft_strcmp(tab[0], "unsetenv") == 0)
	{
		env = ft_forunsetenv(env, tab);
		return (1);
	}
	if (ft_strcmp(tab[0], "setenv") == 0)
	{
		env = ft_forsetenv(env, tab);
		return (1);
	}
	if (ft_strcmp(tab[0], "echo") == 0)
	{
		ft_forecho(str);
		return (1);
	}
	return (0);
}

void	ft_prompt(t_env *env, char **tabenv)
{
	char **path;
	char **cmd;
	char *line;
	char **tab;
	char *path2;
	pid_t pid;
	int i;
	t_env	*tmp;

	tmp = env;
	i = 0;
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
			path = ft_strsplit(env->result, ':');
		env = env->next;
	}
	env = tmp;
	while(42)
	{
		ft_printf("\033[032m$FuckingShell>\033[0m ");
		while (get_next_line(0, &line) == -1)
		{}
		cmd = ft_strsplit(line, ';');
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
				if (tab != NULL)
					ft_free(tab);
					if (cmd != NULL)
						ft_free(cmd);
			//		if (tabenv != NULL)
			//			ft_free(tabenv);
					if (path != NULL)
						ft_free(path);
					ft_freeenv(env);
				ft_printf("\033[033mCiao baby!\033[0m\n");
				kill(pid, 0);
				exit(0);
				break;
			}	
			else
			{

				path2 = ft_strjoin(path[2], "/");
				path2 = ft_strjoin(path2, tab[0]);
				pid = fork();
				if (pid == 0)
				{
					if (execve(path2, tab, tabenv) == -1)
						ft_printf("\033[031mcommand not found: %s\033[0m\n", tab[0]);
					exit(0);
				}
				else
					wait(&pid);
				free(path2);
				ft_free(tab);
				i++;
			}
		}
	} 
}
