/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:19:28 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/23 12:09:33 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_checkopt2(char *str, t_option *opt, int i)
{
	if (str[i] == 'l')
		opt->l = 1;
	if (str[i] == '1' && opt->l == 1)
		opt->l = 0;
	if (str[i] == 'R')
		opt->maj_r = 1;
	if (str[i] == 'a')
		opt->a = 1;
	if (str[i] == 'r')
		opt->r = 1;
	if (str[i] == 't' && opt->maj_s == 0)
		opt->t = 1;
	if (str[i] == 'p')
		opt->p = 1;
	if (str[i] == 'u')
		opt->u = 1;
	if (str[i] == 'S')
	{
		opt->t = 0;
		opt->maj_s = 1;
	}
	if (str[i] == 'c')
		opt->c = 1;
}

void	ft_checkopt(char *str, t_option *opt)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		ft_checkopt2(str, opt, i);
		if (str[i] != 'l' && str[i] != 'R' && str[i] != 'a' && str[i] != 'r' &&
				str[i] != 't' && str[i] != '1' && str[i] != 'S' && str[i] != 'u'
				&& str[i] != 'p' && str[i] != 'c')
		{
			ft_printf("ls: illegal option -- '%c'\nusage: ls [-aclprtuSR1]\n",
					str[i]);
			exit(0);
		}
		i++;
	}
}
