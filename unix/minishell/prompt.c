/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:27:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/14 18:44:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cmd(void)
{
	char	**cmd;
	char	*line;
	int		i;

	ft_printf("\033[032m$FuckingShell>\033[0m ");
	while (get_next_line(0, &line) == -1)
	{
	}
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '&')
			line[i] = ';';
		i++;
	}
	cmd = ft_strsplit(line, ';');
	free(line);
	return (cmd);
}

int		ft_forfree(char *path2, char **tab, int i)
{
	if (path2 != NULL)
		free(path2);
	if (tab != NULL)
		ft_free(tab);
	i++;
	return (i);
}

char	*ft_else(char **path, char **tab, char **tabenv)
{
	char	*path2;
	pid_t	pid;

	path2 = NULL;
	pid = fork();
	if (pid == 0)
		path2 = ft_checkpath(path, tab, tabenv);
	else
		wait(&pid);
	return (path2);
}

int		ft_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '	')
			str[i] = ' ';
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_whileprompt(t_env *env, char **tabenv, char **path, char *path2)
{
	char	**cmd;
	char	**tab;
	int		i;

	while (42)
	{
		cmd = ft_cmd();
		i = 0;
		while (cmd[i])
		{
			tab = NULL;
			if (ft_space(cmd[i]) == 1)
				tab = ft_strsplit(cmd[i], ' ');
			if (tab && ft_strcmp("env", tab[0]) == 0 && tab[1])
				tab = ft_envspe(tab);
			if (tab && ft_built(tab) == 1)
				env = ft_gobuilt(env, tab, cmd[i]);
			else if (tab && ft_strcmp(tab[0], "exit") == 0)
				ft_exit(tab, cmd, path, env);
			else
				path2 = ft_else(path, tab, tabenv);
			i = ft_forfree(path2, tab, i);
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
