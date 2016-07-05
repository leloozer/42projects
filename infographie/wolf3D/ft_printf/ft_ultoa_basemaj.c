/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_basemaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:15:59 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 19:18:46 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

char	*ft_ultoa_basemaj(unsigned long n, unsigned int base)
{
	static char *num;
	char		*str;
	int			i;

	num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = ft_ulenght(n, base);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (base < 2 || base > 35)
	{
		str[i] = '\0';
		return (str);
	}
	while (n > 0)
	{
		str[i] = num[n % base];
		n /= base;
		i--;
	}
	return (str);
}
