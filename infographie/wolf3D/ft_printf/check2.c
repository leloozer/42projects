/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:21:42 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 14:12:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_checkoptionsuite(t_flag *tmp, char *str, int i)
{
	if (str[i] == ' ')
	{
		tmp->space = 1;
		i++;
	}
	return (i);
}

int	ft_checkh(t_flag *tmp, char *str, int i)
{
	int	modif;

	modif = 0;
	while (str[i] == 'h')
	{
		modif++;
		i++;
		if (str[i] != 'h' && str[i - 1] == 'h')
		{
			modif = modif % 2 + 2;
			if (modif == 3)
				tmp->h = 1;
			else if (modif == 2)
				tmp->hh = 1;
		}
	}
	return (i);
}

int	ft_checkl(t_flag *tmp, char *str, int i)
{
	int	modif;

	modif = 0;
	while (str[i] == 'l')
	{
		modif++;
		i++;
		if (str[i] != 'l' && str[i - 1] == 'l')
		{
			modif = modif % 2 + 2;
			if (modif == 3)
				tmp->l = 1;
			else if (modif == 2)
				tmp->ll = 1;
		}
	}
	return (i);
}
