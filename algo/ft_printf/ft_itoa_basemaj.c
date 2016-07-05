/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_basemaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:40:56 by mszczesn          #+#    #+#             */
/*   Updated: 2016/01/21 14:32:11 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static int	ft_lenght(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	i++;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_basemaj(int n, int base) 
{
	static char	*num;
   	char 		*str;
	int			i;

	num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = ft_lenght(n);
	i--;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (base < 2 || base > 35) 
	{ 
		str[i] = '\0'; 
		return (str); 
	}

	if (n < 0)
		n = n * -1;
	while (n > 0) 
	{
		str[i] = num[n % base];
		n /= base;
		i--;
	}
	return (str);
}
