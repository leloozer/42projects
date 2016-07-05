/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:42:29 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/27 17:31:58 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	size_t		size;
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (size == i)
		return ("");
	if (!(str = (char *)malloc(sizeof(*str) * (size - i) + 1)))
		return (NULL);
	size--;
	while (size > 0 && (s[size] == ' ' || s[size] == '\n' || s[size] == '\t'))
		size--;
	while ((i + ++j) <= size)
		str[j] = s[i + j];
	str[j] = '\0';
	return (str);
}
