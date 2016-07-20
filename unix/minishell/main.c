/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:26:25 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/18 17:29:37 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_firstpushback(t_env *env, char *line)
{
	char	**value;

	value = NULL;
	value = ft_strsplit(line, '=');
	env->name = ft_strdup(value[0]);
	env->result = ft_strdup(value[1]);
	env->next = NULL;
	env->prev = NULL;
	ft_free(value);
	value = NULL;
	return (env);
}

t_env	*ft_pushback(t_env *env, char *line)
{
	t_env	*new;
	t_env	*tmp;
	char	**value;

	tmp = env;
	value = NULL;
	while (env->next != NULL)
		env = env->next;
	new = (t_env *)malloc(sizeof(t_env));
	value = ft_strsplit(line, '=');
	new->name = ft_strdup(value[0]);
	new->result = ft_strdup(value[1]);
	new->next = NULL;
	new->prev = env;
	env->next = new;
	env = tmp;
	ft_free(value);
	value = NULL;
	return (env);
}

void	ft_sighandler(int sign)
{
	if (sign == SIGINT)
		return ;
}

void	ft_golst(char **e, int i, t_env *env)
{
	while (e[i])
	{
		if (i == 0)
			env = ft_firstpushback(env, e[i]);
		else
			env = ft_pushback(env, e[i]);
		i++;
	}
}

int		main(int argc, char **argv, char **e)
{
	int		i;
	t_env	*env;
	char	**tab;

	i = 0;
	tab = NULL;
	(void)argc;
	(void)argv;
	ft_printf("\033[033mWelcome to my Shell\033[0m\n");
	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (0);
	if (signal(SIGINT, ft_sighandler) == SIG_ERR)
		ft_printf("\033[031mERROR\033[0m\n");
	if (e[i] == NULL)
	{
		ft_printf("\033[031mNO ENV\033[0m\n");
		return (0);
	}
	ft_golst(e, 0, env);
	tab = ft_envtab(env);
	ft_prompt(env, tab);
	return (0);
}
