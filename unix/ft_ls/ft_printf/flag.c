/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 13:41:30 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 18:26:07 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flag	*ft_initialflag(t_flag *tmp)
{
	tmp->sharp = 0;
	tmp->zero = 0;
	tmp->moins = 0;
	tmp->plus = 0;
	tmp->space = 0;
	tmp->width = 0;
	tmp->precision = 0;
	tmp->hh = 0;
	tmp->h = 0;
	tmp->l = 0;
	tmp->ll = 0;
	tmp->j = 0;
	tmp->z = 0;
	tmp->type = 0;
	return (tmp);
}

int		ft_checkflag(va_list ap, t_flag *tmp, char *str, int i)
{
	tmp = ft_initialflag(tmp);
	i = ft_checkflag2(tmp, str, i);
	ft_checkint(tmp, ap);
	ft_checkchar(tmp, ap);
	ft_checkstr(tmp, ap);
	ft_checkx(tmp, ap);
	ft_checku(tmp, ap);
	ft_checko(tmp, ap);
	ft_checkp(tmp, ap);
	ft_checkcmaj(tmp, ap);
	ft_checksmaj(tmp, ap);
	return (i);
}

int		ft_checkflag2(t_flag *tmp, char *str, int i)
{
	while (str[i] != '\0' && tmp->type == 0)
	{
		i = ft_checkoption(tmp, str, i);
		i = ft_checkwidth(tmp, str, i);
		i = ft_checkprecision(tmp, str, i);
		i = ft_checkmodif(tmp, str, i);
		i = ft_checktype(tmp, str, i);
	}
	return (i);
}
