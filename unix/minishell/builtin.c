/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:02:18 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/11 15:08:58 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		env = tmp;
		ft_pushsetenv(env, tab[1], tab[2]);
	}
	env = tmp;
	return (env);
}

int		ft_forunsetenv3(char *str)
{
	if (str == NULL)
	{
		ft_printf("\033[031munsetenv: usage unsetenv [name]\033[0m\n");
		return (1);
	}
	if (ft_strcmp(str, "PATH") == 0)
	{
		ft_printf("\033[031mNO FREE PATH PLEASE !!!!!!!!\033[0m\n");
		return (1);
	}
	return (0);
}

t_env	*ft_forunsetenv2(t_env *tmp2)
{
	t_env	*tmp3;

	if (tmp2->prev != NULL)
	{
		tmp3 = tmp2->prev;
		if (tmp2->next != NULL)
			tmp3->next = tmp2->next;
		if (tmp2->next == NULL)
			tmp3->next = NULL;
		tmp3->prev = tmp2->prev->prev;
	}
	else
	{
		tmp3 = tmp2->next;
		tmp3->prev = NULL;
	}
	if (tmp2->name != NULL)
		free(tmp2->name);
	if (tmp2->result != NULL)
		free(tmp2->result);
	free(tmp2);
	tmp2 = NULL;
	while (tmp3->prev != NULL)
		tmp3 = tmp3->prev;
	return (tmp3);
}

t_env	*ft_forunsetenv(t_env *env, char **tab)
{
	t_env	*tmp;
	t_env	*tmp2;
	int		ici;

	tmp = env;
	ici = 0;
	if (ft_forunsetenv3(tab[1]) == 1)
		return (env);
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
		env = ft_forunsetenv2(tmp2);
	if (ici == 0)
		env = tmp;
	return (env);
}
