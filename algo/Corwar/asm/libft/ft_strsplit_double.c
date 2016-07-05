/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:42:27 by ndauteui          #+#    #+#             */
/*   Updated: 2016/03/10 19:33:00 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_create_tab(char const *s, char c, char d)
{
	int		i;
	int		j;
	int		word_counter;
	char	**tab;

	i = 0;
	j = 0;
	word_counter = 0;
	while (s[i] != 0)
	{
		while (s[i] == c || s[i] == d)
			i++;
		while ((s[i + j] != c && s[i + j] != d) && s[i + j] != 0)
			j++;
		if (j > 0)
			word_counter++;
		i += j;
		j = 0;
	}
	tab = (char **)malloc(sizeof(char *) * (word_counter + 1));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

static char	*ft_create_word(char const *s, int i, int j)
{
	char	*wrd;
	int		k;

	k = 0;
	wrd = (char *)malloc(sizeof(char) * (j + 1));
	if (wrd == NULL)
		return (NULL);
	while (k + i < j + i)
	{
		wrd[k] = s[k + i];
		k++;
	}
	wrd[k] = '\0';
	return (wrd);
}

static char	**ft_word_copy(char **tab, char const *s, char c, char d)
{
	int		i;
	int		j;
	int		tab_index;

	i = 0;
	j = 0;
	tab_index = 0;
	while (s[i] != 0)
	{
		while (s[i] == c || s[i] == d)
			i++;
		while ((s[i + j] != c && s[i + j] != d) && s[i + j] != 0)
			j++;
		if (j > 0)
		{
			tab[tab_index] = ft_create_word(s, i, j);
			if (tab[tab_index] == NULL)
				return (NULL);
			tab_index++;
		}
		i += j;
		j = 0;
	}
	tab[tab_index] = 0;
	return (tab);
}

char		**ft_strsplit_double(char const *s, char c, char d)
{
	char	**tab;

	if (s && c && d)
	{
		tab = ft_create_tab(s, c, d);
		if (tab == NULL)
			return (NULL);
		tab = ft_word_copy(tab, s, c, d);
		if (tab == NULL)
			return (NULL);
		else
			return (tab);
	}
	return (NULL);
}
