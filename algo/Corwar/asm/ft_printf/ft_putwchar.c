/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:33:00 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 14:14:38 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int		size_bin(unsigned int i)
{
	unsigned int	ret;

	ret = 0;
	while (i)
	{
		i /= 2;
		ret++;
	}
	return (ret);
}

static int			wchar_2(t_wchar w, int prec)
{
	unsigned char	o;
	unsigned long	mask1;

	mask1 = 49280;
	w.o1 = ((w.value >> 6) << 27) >> 27;
	w.o2 = (w.value << 26) >> 26;
	if (prec >= 2 || prec < 0)
	{
		o = (mask1 >> 8) | w.o1;
		write(1, &o, 1);
		o = ((mask1 << 24) >> 24) | w.o2;
		write(1, &o, 1);
		return (2);
	}
	return (0);
}

static int			wchar_3(t_wchar w, int prec)
{
	unsigned char	o;
	unsigned long	mask2;

	mask2 = 14712960;
	w.o1 = ((w.value >> 12) << 28) >> 28;
	w.o2 = ((w.value >> 6) << 26) >> 26;
	w.o3 = (w.value << 26) >> 26;
	if (prec >= 3 || prec < 0)
	{
		o = (mask2 >> 16) | w.o1;
		write(1, &o, 1);
		o = ((mask2 << 16) >> 24) | w.o2;
		write(1, &o, 1);
		o = ((mask2 << 24) >> 24) | w.o3;
		write(1, &o, 1);
		return (3);
	}
	return (0);
}

static int			wchar_4(t_wchar w, int prec)
{
	unsigned char	o;
	unsigned long	mask3;

	mask3 = 4034953344;
	w.o1 = ((w.value >> 18) << 29) >> 29;
	w.o2 = ((w.value >> 12) << 26) >> 26;
	w.o3 = ((w.value >> 6) << 26) >> 26;
	w.o4 = (w.value << 26) >> 26;
	if (prec >= 4 || prec < 0)
	{
		o = (mask3 >> 24) | w.o1;
		write(1, &o, 1);
		o = ((mask3 << 8) >> 24) | w.o2;
		write(1, &o, 1);
		o = ((mask3 << 16) >> 24) | w.o3;
		write(1, &o, 1);
		o = ((mask3 << 24) >> 24) | w.o4;
		write(1, &o, 1);
		return (4);
	}
	return (0);
}

int					ft_putwchar(wchar_t c, t_flag *tmp, int prec)
{
	t_wchar			w;

	w.value = c;
	w.size = size_bin(w.value);
	if (w.size <= 7)
	{
		ft_putchar((char)c);
		tmp->nbprint = tmp->nbprint + 1;
		return (0);
	}
	else if (w.size <= 11)
	{
		tmp->nbprint = tmp->nbprint + 1;
		return (wchar_2(w, prec));
	}
	else if (w.size <= 16)
	{
		tmp->nbprint = tmp->nbprint + 2;
		return (wchar_3(w, prec));
	}
	else
	{
		tmp->nbprint = tmp->nbprint + 3;
		return (wchar_4(w, prec));
	}
}
