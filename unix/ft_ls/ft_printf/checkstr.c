/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:44:22 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 15:38:07 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_checkstr(t_flag *tmp, va_list ap)
{
	char	*str;
	int		nbr;

	if (tmp->type == 's' && tmp->l == 1)
		tmp->type = 'S';
	if (tmp->type == 's')
	{
		if (tmp->moins == 1)
			tmp->zero = 0;
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		if (tmp->precision == 0)
			nbr = ft_strlen(str);
		if (tmp->precision != 0)
		{
			nbr = tmp->precision;
			str = ft_strprecision(str, nbr);
		}
		nbr = ft_strlen(str);
		tmp->nbprint = tmp->nbprint + nbr;
		ft_checkstrsuite(tmp, str, nbr);
	}
}

void	ft_checkstrsuite(t_flag *tmp, char *str, int nbr)
{
	if ((tmp->width != 0) && (tmp->moins == 0))
		ft_lookwidth2(tmp, nbr);
	if (tmp->precision != 1)
		ft_putstr(str);
	if ((tmp->width != 0) && (tmp->moins == 1))
		ft_lookwidth2(tmp, nbr);
}

void	ft_lookwidth2(t_flag *tmp, int nbr)
{
	tmp->width = tmp->width - nbr;
	while ((tmp->width > 0) && (tmp->zero == 0))
	{
		ft_putchar(' ');
		tmp->nbprint = tmp->nbprint + 1;
		tmp->width = tmp->width - 1;
	}
	while ((tmp->width > 0) && (tmp->zero == 1))
	{
		ft_putchar('0');
		tmp->nbprint = tmp->nbprint + 1;
		tmp->width = tmp->width - 1;
	}
}

char	*ft_strprecision(char *str, int n)
{
	int		i;
	char	*str2;

	i = 0;
	if (!(str2 = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (n > 0)
	{
		str2[i] = str[i];
		i++;
		n--;
	}
	str2[i] = '\0';
	return (str2);
}
