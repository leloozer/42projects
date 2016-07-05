/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:35:19 by mszczesn          #+#    #+#             */
/*   Updated: 2016/01/19 12:27:57 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdint.h>


void	ft_checkint(t_flag *tmp, va_list ap)
{
	int nbr;

	if (tmp->type == 'd' || tmp-> type == 'D' || tmp->type == 'i' || 
			tmp->type == 'u' || tmp->type == 'U')
	{
		if (tmp->space == 1)  
			tmp->plus = 0;
//		ft_lookformat(tmp, nbr);
		nbr = va_arg(ap, int);
//ft_lookstar(tmp, ap);
		ft_lookwidth(tmp, nbr);
		ft_printplus_spaceint(tmp, nbr);
		ft_putnbr(nbr);
	}
}

/*void ft_lookformat(t_flag *tmp, long long nbr)
{	
	if (tmp->ll == 1 && (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D'))
		(long long)nbr = (long long)va_arg(ap, int);
	if (tmp->l == 1 && (tmp->type == 'd' || tmp->type == 'i' || tmp->type =='D'))
		(long)nbr = (long)va_arg(ap, int);
	if (tmp->j == 1)
		(intmax_t)nbr = (intmax_t)va_arg(ap, int);
	if (tmp->z == 1)
		(size_t)nbr = (size_t)va_arg(ap, int);
}*/

void	ft_lookwidth(t_flag *tmp, int nbr)
{
	int	i;

	i = 0;
	if (tmp->width != 0)
	{
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
		if (tmp->plus == 1)
			i++;
		if (tmp->space == 1)
			i++;
		tmp->width = tmp->width - i;
		if(tmp->zero == 0)
		{
			while (tmp->width > 0)
			{
				ft_putchar(' ');
				tmp->width = tmp->width - 1;
			}
		}
		if (tmp->zero == 1 && tmp->width != 0)
		{
			while (tmp->width > 0)
			{
				ft_putchar('0');
				tmp->width = tmp->width -1;
			}
		}
	}
}

/*void	ft_lookstar(t_flag *tmp, va_list ap)
{
	tmp->width = va_arg(ap, int);	
}*/

void	ft_printplus_spaceint (t_flag *tmp, int nbr)
{
	if ((tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
			&& tmp->space == 1 && nbr >= 0)
		ft_putchar(' ');
	if ((tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D') 
			&& tmp->plus == 1 && nbr >= 0)
		ft_putchar('+');
}
