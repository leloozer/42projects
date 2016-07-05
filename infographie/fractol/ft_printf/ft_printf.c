/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:06:50 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 14:53:56 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

int	ft_afterpourcent(va_list ap, t_flag *tmp, char *str, int i)
{
	if (str[i + 1] == '%')
	{
		ft_putchar('%');
		tmp->nbprint = tmp->nbprint + 1;
		return (i + 2);
	}
	else
	{
		i++;
		i = ft_checkflag(ap, tmp, str, i);
	}
	return (i);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		nbprint;
	t_flag	*tmp;

	i = 0;
	if (!(tmp = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	tmp->nbprint = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i = ft_afterpourcent(ap, tmp, str, i);
		else
		{
			ft_putchar(str[i]);
			tmp->nbprint = tmp->nbprint + 1;
			i++;
		}
	}
	nbprint = tmp->nbprint;
	free(tmp);
	va_end(ap);
	return (nbprint);
}
