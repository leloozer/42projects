/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 13:42:23 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 14:12:46 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_checkoption(t_flag *tmp, char *str, int i)
{
	if (str[i] == '#')
	{
		tmp->sharp = 1;
		i++;
	}
	if (str[i] == '0')
	{
		tmp->zero = 1;
		i++;
	}
	if (str[i] == '+')
	{
		tmp->plus = 1;
		i++;
	}
	if (str[i] == '-')
	{
		tmp->moins = 1;
		i++;
	}
	i = ft_checkoptionsuite(tmp, str, i);
	return (i);
}

int	ft_checkwidth(t_flag *tmp, char *str, int i)
{
	int		largminim;

	if (str[i] >= '1' && str[i] <= '9')
	{
		largminim = str[i] - '0';
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			largminim = largminim * 10 + (str[i] - '0');
			i++;
		}
		tmp->width = largminim;
		return (i);
	}
	else
	{
		return (i);
	}
}

int	ft_checkprecision(t_flag *tmp, char *str, int i)
{
	int		prec;

	if (str[i] == '.')
	{
		i++;
		if (str[i] == '0')
			tmp->precision = 1;
		if (str[i] >= '1' && str[i] <= '9')
		{
			prec = str[i] - '0';
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				prec = prec * 10 + (str[i] - '0');
				i++;
			}
			tmp->precision = prec;
		}
		return (i);
	}
	else
		return (i);
}

int	ft_checkmodif(t_flag *tmp, char *str, int i)
{
	if (str[i] == 'h')
		i = ft_checkh(tmp, str, i);
	if (str[i] == 'l')
		i = ft_checkl(tmp, str, i);
	if (str[i] == 'j')
	{
		i++;
		tmp->j = 1;
	}
	if (str[i] == 'z')
	{
		i++;
		tmp->z = 1;
	}
	return (i);
}

int	ft_checktype(t_flag *tmp, char *str, int i)
{
	int		count;
	char	*s;

	count = 0;
	s = "sSpdDioOuUxXcC";
	while (s[count] != '\0')
	{
		if (str[i] == s[count])
			tmp->type = str[i];
		count++;
	}
	if (tmp->type != 0)
	{
		i++;
		return (i);
	}
	else
		return (i);
}
