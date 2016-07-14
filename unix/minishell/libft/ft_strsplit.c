/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:44:34 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/14 17:42:24 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t		get_size(const char *str, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	while (*str)
	{
		i = 0;
		while (str[i] != c && str[i])
			++i;
		size = i ? size + 1 : size;
		str += i;
		str = *str ? str + 1 : str;
	}
	return (size);
}

char		**stuff_me(const char *str, char c, char **split)
{
	size_t		len;
	char		**ptr;

	ptr = split;
	while (*str)
	{
		len = 0;
		while (str[len] != c && str[len])
			++len;
		if (len)
		{
			*split = ft_strsub(str, 0, len);
			++split;
		}
		str += len;
		str = *str ? str + 1 : str;
	}
	return (ptr);
}

char		**ft_strsplit(const char *str, char c)
{
	size_t		size;
	char		**split;

	size = get_size(str, c);
	if (!(split = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	split = stuff_me(str, c, split);
	split[size] = 0;
	return (split);
}
