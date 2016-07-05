/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:15:46 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/24 15:25:29 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int i)
{
	if (i == -1)
	{
		ft_printf("\033[0;33mERROR\033[0m\n");
		exit(1);
	}
}

void	ft_map(t_data *data, t_map *map)
{
	int ret;

	while ((ret = get_next_line(data->fd, &data->line) == 1))
	{
		data->table = ft_strsplit(data->line, ' ');
		data->x = -1;
		while (data->table[++data->x] != NULL)
		{
			map->next = ft_initmap();
			map->z = ft_atoi(data->table[data->x]);
			if (map->z > data->z_max)
				data->z_max = map->z;
			map->x = data->x;
			map->y = data->y;
			map = map->next;
		}
		data->y++;
	}
	if (ret != 0)
		ft_error(-1);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	j = ft_strlen(str) - 1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (j >= 0)
	{
		tmp[i] = str[j];
		i++;
		j--;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_checkfile(char *file)
{
	char *rev;

	rev = ft_strrev(file);
	if (rev[0] != 'f' || rev[1] != 'd' || rev[2] != 'f' || rev[3] != '.')
		ft_error(-1);
}

int		ft_parse(char *file, t_data *data)
{
	t_map	*map;

	data->z_max = 0;
	ft_checkfile(file);
	if ((map = (t_map *)malloc(sizeof(*map))) == NULL)
		ft_error(-1);
	data->first = map;
	if ((data->fd = open(file, O_RDWR)) == -1)
		ft_error(-1);
	data->y = 0;
	if (data->fd == -1)
		ft_error(-1);
	ft_map(data, map);
	map = data->first;
	while (map->next != NULL)
	{
		map->z_max = data->z_max;
		map = map->next;
	}
	data->lenght_line = data->x;
	if (close(data->fd) == -1)
		ft_error(-1);
	return (0);
}
