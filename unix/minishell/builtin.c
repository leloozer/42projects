/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:02:18 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/07 14:22:58 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_forenv(t_env *env, char **tab)
{
	t_env *tmp;

	tmp = env;
	ft_free(tab);
	while (env)
	{
		ft_printf("%s=%s\n", env->name, env->result);
		env = env->next;
	}
	env = tmp;
}

int		ft_forsetenv2(t_env *env, char **tab)
{
	int	ici;

	ici = 0;
	while (env)
	{
		if ((ft_strcmp(env->name, tab[1]) == 0) &&
				(ft_strcmp(tab[3], "0") != 0))
		{
			ici = 1;
			env->result = ft_strdup(tab[2]);
		}
		env = env->next;
	}
	return (ici);
}

t_env	*ft_forsetenv(t_env *env, char **tab)
{
	t_env	*tmp;
	int		ici;
	char	*line;

	tmp = env;
	ici = 0;
	if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL)
	{
		ft_printf("\033[031msetenv: usage setenv [name] [value] ");
		ft_printf("[number]\033[0m\n");
		return (env);
	}
	ici = ft_forsetenv2(env, tab);
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

void	ft_forunsetenv2(t_env *tmp2)
{
	t_env	*tmp3;

	tmp3 = tmp2->prev;
	tmp3->next = tmp2->next;
	free(tmp2->name);
	free(tmp2->result);
	free(tmp2->prev);
}

t_env	*ft_forunsetenv(t_env *env, char **tab)
{
	t_env	*tmp;
	t_env	*tmp2;
	int		ici;

	tmp = env;
	ici = 0;
	if (tab[1] == NULL)
	{
		ft_printf("\033[031munsetenv: usage unsetenv [name]\033[0m\n");
		return (env);
	}
	while (env)
	{
		if ((ft_strcmp(env->name, tab[1]) == 0))
		{
			ici = 1;
			tmp2 = env;
		}
		env = env->next;
	}
	if (ici == 1)
		ft_forunsetenv2(tmp2);
	env = tmp;
	return (env);
}
