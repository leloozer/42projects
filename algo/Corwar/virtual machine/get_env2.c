/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/10 16:28:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	*data_dup(char *buf, int len)
{
	int				size;
	int				i;
	unsigned char	*dup;

	i = 0;
	size = len - sizeof(t_header);
	dup = (unsigned char *)malloc(len);
	while (i < size)
	{
		dup[i] = (unsigned char)buf[i];
		i++;
	}
	return (dup);
}

void			set_champion(char *buf, t_env *env, int num, int len)
{
	env->players[num].number = num + 1;
	env->players[num].name = ft_strdup(buf + 4);
	env->players[num].comment = ft_strdup(buf + PROG_NAME_LENGTH + 12);
	env->players[num].data = data_dup(buf + sizeof(t_header), len);
	env->players[num].size = len - sizeof(t_header);
	env->players[num].live = 0;
}

void			read_cor(t_env *env, int num, char *fname)
{
	int		len;
	int		fd;
	int		size;
	char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + CHAMP_MAX_SIZE];

	size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + CHAMP_MAX_SIZE;
	if ((fd = open(fname, O_RDONLY)) == -1)
		ft_error2("Error : can't read source file ", fname);
	len = read(fd, buf, size);
	set_champion(buf, env, num, len);
	close(fd);
}
