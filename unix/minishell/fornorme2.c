/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fornorme2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:30:20 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/18 17:32:46 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_forenv(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (env)
	{
		ft_printf("%s=%s\n", env->name, env->result);
		env = env->next;
	}
	env = tmp;
}

char	*ft_mallocname(char *name, char *line, int k)
{
	int	j;

	j = 0;
	while (line[k] != ' ' && line[k] != '\0' && line[k] != '"')
	{
		k++;
		j++;
	}
	name = (char *)malloc(sizeof(char) * j + 1);
	return (name);
}

int		ft_checkenv(t_env *env, char *name)
{
	t_env *tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(name, env->name) == 0)
		{
			ft_printf(" %s", env->result);
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	if (name != NULL)
		free(name);
	return (0);
}

int		ft_echoenv(char *line, int i, t_env *env)
{
	char	*name;
	int		j;
	int		k;
	int		found;

	j = 0;
	found = 0;
	name = NULL;
	k = i + 1;
	name = ft_mallocname(name, line, k);
	k = i + 1;
	while (line[k] != ' ' && line[k] != '\0' && line[k] != '"')
	{
		name[j] = line[k];
		k++;
		j++;
	}
	name[j++] = '\0';
	found = ft_checkenv(env, name);
	if (found == 1)
		return (k);
	return (i);
}
