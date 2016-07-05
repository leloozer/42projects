/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checko.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:54:08 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 16:56:35 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_checko(t_flag *tmp, va_list ap)
{
	char	*str;
	int		i;

	if (tmp->type == 'o' || tmp->type == 'O')
	{
		ft_tmpforo(tmp);
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 1)
			str = ft_toa_basemodif(tmp, ap, 8);
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 0)
			str = ft_lltoa_base((va_arg(ap, unsigned int)), 8);
		i = ft_strlen(str);
		tmp->nbprint = tmp->nbprint + i;
		ft_checkosuite(tmp, i, str);
	}
}

void	ft_checkosuite(t_flag *tmp, int i, char *str)
{
	int	j;

	j = 0;
	if (tmp->precision > i)
	{
		if (tmp->moins == 1)
			tmp->sharp = 0;
		j = tmp->precision - i;
		i = tmp->precision;
	}
	if (tmp->width != 0 && tmp->moins == 0)
		ft_lookwidtho(tmp, i);
	if (tmp->sharp == 1)
	{
		write(1, "0", 1);
		tmp->nbprint = tmp->nbprint + 1;
	}
	if (tmp->precision != 0)
		ft_printprecision(tmp, j);
	ft_putstr(str);
	if (tmp->width != 0 && tmp->moins == 1)
		ft_lookwidtho(tmp, i);
}

void	ft_tmpforo(t_flag *tmp)
{
	if (tmp->type == 'O')
		ft_modifmaj(tmp);
	if (tmp->moins == 1 || tmp->precision != 0)
		tmp->zero = 0;
}

void	ft_lookwidtho(t_flag *tmp, int i)
{
	if (tmp->sharp == 1)
		i++;
	tmp->width = tmp->width - i;
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
