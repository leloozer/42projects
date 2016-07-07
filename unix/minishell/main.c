/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:26:25 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/07 14:00:05 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_firstpushback(t_env *env, char *line)
{
	char	**value;

	value = ft_strsplit(line, '=');
	env->name = ft_strdup(value[0]);
	env->result = ft_strdup(value[1]);
	env->next = NULL;
	env->prev = NULL;
}

void	ft_pushback(t_env *env, char *line)
{
	t_env *new;
	t_env *tmp;	
	char **value;

	tmp = env;
	while (env->next)
	{
		env = env->next;
	}
	new = (t_env *)malloc(sizeof(t_env *));
	value = ft_strsplit(line, '=');
	new->name = ft_strdup(value[0]);
	new->result = ft_strdup(value[1]);
	new->next = NULL;
	new->prev = env;
	env->next = new;
	env = tmp;
}

void	ft_handle_sig(int sig)
{
	if (sig == SIGINT)
		return;
}

int main (int argc, char **argv, char **e)
{
	(void)argc;
	(void)argv;
	int	i;
//	struct termios	term;
//	struct termios	new_term;
	t_env	*env;
	char	**tab;

	i = 0;
	env = (t_env *)malloc(sizeof(t_env));
//	tcgetattr(0, &term);
//	new_term = term;
//	new_term.c_cc[VEOF] = 3;
//	tcsetattr(0, TCSANOW, &new_term);
//	if (signal(SIGINT, ft_handle_sig) == SIG_ERR)
//		ft_putendl("Error");
	if (e[i] == NULL)
	{
		ft_printf("\033[031mERROR\033[0m\n");
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
	return  (0);
}
