/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:43:52 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 16:40:42 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>
#include <stdio.h>

void	ft_checkint(t_flag *tmp, va_list ap)
{
	void	*nbr;
	int		len;
	int		lenprecision;

	lenprecision = 0;
	if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
	{
		nbr = va_arg(ap, void *);
		if (nbr == NULL)
			nbr = 0;
		if (tmp->type == 'D')
			ft_modifmaj(tmp);
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 1)
			len = ft_lenmodif(tmp, nbr);
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 0)
			len = ft_len((int)nbr);
		tmp->nbprint = tmp->nbprint + len;
		if (tmp->precision > len)
		{
			lenprecision = tmp->precision - len;
			len = tmp->precision;
		}
		ft_checkintsuite(tmp, len, lenprecision, nbr);
	}
}

void	ft_printprecision(t_flag *tmp, int lenprecision)
{
	while (lenprecision > 0)
	{
		write(1, "0", 1);
		tmp->nbprint = tmp->nbprint + 1;
		lenprecision--;
	}
}

int		ft_len(long long nbr)
{
	int		i;

	i = 0;
	if (nbr == LONG_MIN)
		return (20);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	i++;
	return (i);
}

void	ft_lookwidth(t_flag *tmp, int i)
{
	if (tmp->space == 1)
		i++;
	if (tmp->plus == 1)
		i++;
	if (tmp->width != 0)
	{
		tmp->width = tmp->width - i;
		if (tmp->zero == 0)
		{
			while (tmp->width > 0)
			{
				ft_putchar(' ');
				tmp->nbprint = tmp->nbprint + 1;
				tmp->width = tmp->width - 1;
			}
		}
		if (tmp->zero == 1 && tmp->width != 0)
			ft_lookwidthsuite(tmp);
	}
}

void	ft_printplus_spaceint(t_flag *tmp, int nbr)
{
	if ((tmp->type == 'd' || tmp->type == 'i')
			&& tmp->space == 1 && nbr >= 0)
	{
		ft_putchar(' ');
		tmp->nbprint = tmp->nbprint + 1;
	}
	if ((tmp->type == 'd' || tmp->type == 'i')
			&& tmp->plus == 1)
	{
		ft_putchar('+');
		tmp->nbprint = tmp->nbprint + 1;
	}
}
