/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:33:22 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/14 17:31:07 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pushsetenv(t_env *env, char *str, char *str2)
{
	t_env *new;

	new = (t_env *)malloc(sizeof(t_env));
	while (env->next != NULL)
		env = env->next;
	new->next = NULL;
	new->name = ft_strdup(str);
	new->result = ft_strdup(str2);
	new->prev = env;
	env->next = new;
}

int		ft_lenenv(t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (env)
	{
		i++;
		env = env->next;
	}
	env = tmp;
	return (i);
}

char	**ft_envspe(char **tab)
{
	int j;

	j = 1;
	while (tab[j])
	{
		tab[j - 1] = ft_strdup(tab[j]);
		j++;
	}
	tab[j - 1] = NULL;
	return (tab);
}

char	*ft_add(char *name, char *result)
{
	char	*src;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(name) + ft_strlen(result);
	src = (char *)malloc(sizeof(char) * len + 1);
	while (name[i])
	{
		src[i] = name[i];
		i++;
	}
	src[i] = '=';
	i++;
	while (result[j])
	{
		src[i + j] = result[j];
		j++;
	}
	src[i + j] = '\0';
	return (src);
}

char	**ft_envtab(t_env *env)
{
	char	**tab;
	int		i;
	int		len;

	i = 0;
	len = ft_lenenv(env);
	tab = (char **)malloc(sizeof(char) * len + 1);
	while (env)
	{
		if (env->result == NULL)
			env->result = ft_strdup("0");
		tab[i] = ft_add(env->name, env->result);
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
