/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fornorme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:27:07 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/18 17:37:35 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cmd(void)
{
	char	**cmd;
	char	*line;
	int		i;

	cmd = NULL;
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

void	ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	tab = NULL;
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
		free(tmp);
		tmp = NULL;
	}
}
