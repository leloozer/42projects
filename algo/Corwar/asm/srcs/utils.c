/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:09:59 by ndauteui          #+#    #+#             */
/*   Updated: 2016/03/28 18:48:34 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_isalnum_string(char *str, char a, char b, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 1 || c == '_')
			i++;
		else if (a != -1 && str[i] == a)
			i++;
		else if (b != -1 && str[i] == b)
			i++;
		else if (c != -1 && str[i] == c)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_isdigit_string(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_implode(char **split)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (split[i])
	{
		ret = ft_strjoin(ret, split[i]);
		i++;
	}
	return (ret);
}

char	*ft_implode_c(char **split, char *c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (split[i])
	{
		ret = ft_strjoin(ret, split[i]);
		ret = ft_strjoin(ret, c);
		i++;
	}
	return (ret);
}

char	*ft_strtrim_comment(char *str)
{
	unsigned int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == COMMENT_CHAR || str[pos] == ';')
			break ;
		pos++;
	}
	if (pos == ft_strlen(str) - 1)
		return (str);
	return (ft_strsub(str, 0, pos));
}
