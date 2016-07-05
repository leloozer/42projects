/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:10:58 by nfruneau          #+#    #+#             */
/*   Updated: 2014/03/22 19:42:32 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_stopbuf(const char *buf)
{
	size_t	i;

	i = 0;
	if (buf == NULL)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

int		ft_ret(int ret)
{
	if (ret == -1)
		return (-1);
	else
		return (0);
}

char	*ft_strcut(char *buf)
{
	size_t	j;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strndup((const char *)buf, ft_stopbuf(buf));
	j = ft_strlen((const char *)buf) - ft_strlen((const char *)tmp);
	tmp2 = ft_strsub((const char *)buf, (ft_stopbuf(buf) + 1), j);
	ft_strcpy(buf, (const char *)tmp2);
	free(tmp2);
	return (tmp);
}

int		ft_get_next_read(int const fd, char **line, int i, char *buf)
{
	int		j;
	int		ret;
	char	*tmp;
	char	*tmp2;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		j = ft_find_char(buf, '\n');
		if (i == 0)
			*line = ft_strcut(buf);
		else
		{
			tmp = ft_strdup(*line);
			free(*line);
			tmp2 = ft_strcut(buf);
			*line = ft_strjoin(tmp, tmp2);
			free(tmp);
			free(tmp2);
		}
		if (j == 1)
			return (1);
		i++;
	}
	return (ft_ret(ret));
}

int		get_next_line(int const fd, char **line)
{
	int			i;
	static char	buf[BUFF_SIZE + 1];

	i = 0;
	*line = NULL;
	if (ft_strlen((const char *)buf) > 0)
	{
		i = ft_find_char(buf, '\n');
		*line = ft_strcut(buf);
		if (i == 1)
			return (1);
		else
			i++;
	}
	return (ft_get_next_read(fd, line, i, buf));
}
