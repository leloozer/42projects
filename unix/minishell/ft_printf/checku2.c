/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checku2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:55:01 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 17:21:35 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_tmpforu(t_flag *tmp)
{
	tmp->space = 0;
	tmp->plus = 0;
	if (tmp->type == 'U' && tmp->z == 0)
		ft_modifmaj(tmp);
	if (tmp->precision != 0)
		tmp->zero = 0;
}

int		ft_nbrpos(t_flag *tmp, int len)
{
	int	lenprecision;

	lenprecision = 0;
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
	return (len);
}

int		ft_lenu(t_flag *tmp, int nbr, size_t nbrz, unsigned char nbrhh)
{
	int len;

	len = 0;
	if (tmp->z == 0 && tmp->hh == 0)
		len = ft_len(nbr);
	if (tmp->z == 1)
		len = ft_len(nbrz);
	if (tmp->hh == 1)
		len = ft_len(nbrhh);
	return (len);
}

void	ft_printu(t_flag *tmp, int nbr, size_t nbrz, unsigned char nbrhh)
{
	if (tmp->z == 0 && tmp->hh == 0)
		ft_putnbr(nbr);
	if (tmp->z == 1)
		ft_putznbr(nbrz);
	if (tmp->hh == 1)
		ft_puthhnbr(nbrhh);
}

void	ft_umoins(t_flag *tmp, int len)
{
	if (tmp->moins == 1)
	{
		tmp->zero = 0;
		ft_lookwidth(tmp, len);
	}
}
