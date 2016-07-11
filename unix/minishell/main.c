/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:26:25 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/11 14:57:39 by mszczesn         ###   ########.fr       */
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
		tab[i] = NULL;
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
		free(tmp);
		tmp = NULL;
	}
}

void	ft_firstpushback(t_env *env, char *line)
{
	char	**value;

	value = ft_strsplit(line, '=');
	env->name = value[0];
	env->result = value[1];
	env->next = NULL;
	env->prev = NULL;
}

void	ft_pushback(t_env *env, char *line)
{
	t_env	*new;
	t_env	*tmp;
	char	**value;

	tmp = env;
	while (env->next != NULL)
		env = env->next;
	new = (t_env *)malloc(sizeof(t_env *));
	value = ft_strsplit(line, '=');
	new->name = value[0];
	new->result = value[1];
	new->next = NULL;
	new->prev = env;
	env->next = new;
	env = tmp;
	ft_free(value);
	value = NULL;
}

int		main(int argc, char **argv, char **e)
{
	int		i;
	t_env	*env;
	char	**tab;

	i = 0;
	(void)argc;
	(void)argv;
	env = (t_env *)malloc(sizeof(t_env));
	if (e[i] == NULL)
	{
		ft_printf("\033[031mNO ENV\033[0m\n");
		return (0);
	}
	while (e[i])
	{
		if (i == 0)
			ft_firstpushback(env, e[i]);
		else
			ft_pushback(env, e[i]);
		i++;
	}
	tab = ft_envtab(env);
	ft_prompt(env, tab);
	return (0);
}
