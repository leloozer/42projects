/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:14:58 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/30 12:12:15 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	size;

	i = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		str = (char *)malloc(sizeof(s) * size + 1);
		if (str)
		{
			while (s[i] != '\0')
			{
				str[i] = (*f)(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
