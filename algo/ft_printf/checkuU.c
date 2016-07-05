/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkuU.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 12:04:28 by mszczesn          #+#    #+#             */
/*   Updated: 2016/01/29 16:41:54 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdint.h>

void	ft_checkuU(t_flag *tmp, va_list ap)
{
	int nbr;
	int len;
	int lenprecision;
	size_t nbrz;
	unsigned char nbrhh;

	lenprecision = 0;
	if (tmp->type == 'u' || tmp->type == 'U')
	{
		if(tmp->type == 'U' && tmp->z == 0)
			ft_modifmaj(tmp);
		if (tmp->precision != 0)
			tmp->zero = 0;
		tmp->space = 0;
		tmp->plus = 0;
		if(tmp->z == 0 && tmp->hh == 0)
			nbr = va_arg(ap, unsigned int);
		if(tmp->z == 1 && tmp->hh == 0)
			nbrz = va_arg(ap, size_t);
		if(tmp->hh == 1)
			nbrhh = va_arg(ap, int);
		if (nbr < 0 && tmp->z == 0)
			ft_nbrneg(tmp, nbr);
		if (nbr >= 0 && tmp->z == 0 && tmp->hh == 0)
			len = ft_len(nbr);
		if (nbr >= 0 && tmp->z == 1)
		   len = ft_len(nbrz);
		if (nbr >= 0 && tmp->hh == 1)
			len = ft_len(nbrhh);
		if (nbr >= 0)
		{	
			tmp->nbprint = tmp->nbprint + len;
			if (tmp->precision > len)
			{
				lenprecision = tmp->precision - len;
				len = tmp->precision;
			}
			if (tmp->moins == 0)
				ft_lookwidth(tmp, len);
			if (tmp->precision != 0)
				ft_printprecision(tmp, lenprecision);
			if (tmp->z == 0 && tmp->hh == 0)
				ft_putnbr(nbr);
			if (tmp->z == 1)
				ft_putznbr(nbrz);
			if (tmp->hh == 1)
				ft_puthhnbr(nbrhh);
			if (tmp->moins == 1)
			{
				tmp->zero = 0;
				ft_lookwidth(tmp, len);
			}
		}
	}
}

void	ft_nbrneg(t_flag *tmp, int nbr)
{
	unsigned long int	max;
	int len;
	int lenprecision;

	lenprecision = 0;
	max = 4294967295;
	nbr = nbr * -1;
	max = max - nbr + 1;
	len = ft_lenuint(max);
	tmp->nbprint =tmp->nbprint + len;
	if (tmp->precision > len)
	{
		lenprecision = tmp->precision - len;
		len = tmp->precision;
	}
	if (tmp->moins == 0)
		ft_lookwidth(tmp, len);
	if (tmp->precision != 0)
		ft_printprecision(tmp, lenprecision);
	ft_putnbruint(max);
	if (tmp->moins == 1)
	{
		tmp->zero = 0;
		ft_lookwidth(tmp, len);
	}
}

void ft_forz(t_flag *tmp, size_t nbr)
{
	unsigned long int  max;
	int len;
	int lenprecision;

	max = 4294967295;
	lenprecision = 0;
	nbr = nbr * -1;
	if (tmp->type == 'u')
		max = max + nbr + 1;
	if (tmp->type == 'U')
		max = max * 2 + nbr + 1;
	len = ft_lenuint(max);
	tmp->nbprint =tmp->nbprint + len;
	if (tmp->precision > len)
	{
		lenprecision = tmp->precision - len;
		len = tmp->precision;
	}
	if (tmp->moins == 0)
		ft_lookwidth(tmp, len);
	if (tmp->precision != 0)
		ft_printprecision(tmp, lenprecision);
	ft_putnbruint(max);
	if (tmp->moins == 1)
	{
		tmp->zero = 0;
		ft_lookwidth(tmp, len);
	}
}

int	ft_lenuint(unsigned int max)
{
	int i;

	i = 0;
	while (max > 9)
	{
		max = max / 10;
		i++;
	}
	i++;
	return (i);
}

