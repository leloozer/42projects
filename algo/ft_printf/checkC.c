/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkC.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:37:59 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 12:05:48 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_checkC(t_flag *tmp, va_list ap)
{
	wchar_t c;
	unsigned int	size;

	if (tmp->type == 'C')
	{
		c = (wchar_t)va_arg(ap, wint_t);
		if (tmp->space == 1)
			tmp->width++;
		size = size_bin(c);
		if (size <= 7)
			tmp->width = tmp->width;
		else if (size <= 11)
			tmp->width -= 2;
		else if (size <= 16)
			tmp->width -= 3;
		else
			tmp->width -= 4;
		if (tmp->moins == 0)
			ft_lookwidth(tmp, 0);
		ft_putwchar(c, 4);
			tmp->nbprint = tmp->nbprint + 4;
		if (tmp->moins == 1)
			ft_lookwidth(tmp, 0);
	}	
}

void	ft_checkS(t_flag *tmp, va_list ap)
{
	wchar_t	*str;
	unsigned int	size;

	if (tmp->type == 'S')
	{
		str = ft_wstrdup(va_arg(ap, wchar_t *));
	if (tmp->precision != 0)
			str[tmp->precision] = (wchar_t)0;
	size = ft_wstrlen(str);
	if (tmp->moins == 0)
		ft_lookwidth2(tmp, size);
	ft_putwstr(str, tmp->precision);
	tmp->nbprint = tmp->nbprint + size;
	if (tmp->moins == 1)
		ft_lookwidth2(tmp, size);
	}
}

int			ft_putwstr(wchar_t *str, int prec)
{
	int		i;
	int		ret;
	int		c;

	i = 0;
	ret = 0;
	if (prec == 0)
		prec = 4096;
	while (str[i] && prec > 0)
	{
		c = ft_putwchar(str[i], prec);
		prec -= c;
		ret += c;
		i++;
	}
	return (ret);
}

wchar_t			*ft_wstrdup(wchar_t *str)
{
	size_t		len;
	wchar_t		*new;
	int			i;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = ft_wstrlen(str) + 1;
	new = (wchar_t *)malloc(sizeof(wchar_t) * len);
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t		ft_wstrlen(wchar_t *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
