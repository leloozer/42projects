/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:33:22 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/28 21:05:37 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lenenv(t_env *env)
{
	t_env *tmp;
	int 	i;

	i = 0;
	tmp = env;
	while(env)
	{
		i++;
		env = env->next;
	}
	env = tmp;
	return (i);
}

char *ft_add(char *name, char *result)
{
	char	*src;
	int	len;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	len = ft_strlen(name) + ft_strlen(result) + 1;
	src = (char *)malloc(sizeof(char) * len + 1);
	while(name[i])
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

char **ft_envtab(t_env *env)
{
	char **tab;
	int	i;
	int	len;

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
