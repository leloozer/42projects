/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:20:58 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/27 17:36:26 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wordsnb(char const *s, char c)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c && s[i] != '\0')
			result++;
		if (s[0] != c && i == 0)
			result++;
		i++;
	}
	return (result);
}

static char	ft_strlensplit(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_subchain(char const *s, char c, int j)
{
	int		k;
	int		sizeword;
	char	*str;

	k = 0;
	while (s[j] && s[j] == c)
		j++;
	sizeword = ft_strlensplit(&s[j], c);
	if (!(str = (char *)malloc(sizeof(*str) * sizeword + 1)))
		return (NULL);
	while (k < sizeword)
	{
		str[k] = s[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		wordsnb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wordsnb = ft_wordsnb(s, c);
	if (!(str = (char **)malloc(sizeof(*str) * wordsnb + 1)))
		return (NULL);
	while (i < wordsnb)
	{
		str[i] = ft_subchain(&s[j], c, j);
		j += ft_strlen(str[i]);
		i++;
	}
	return (str);
}
