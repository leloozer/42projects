/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/10 16:28:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	data_to_uint(char *data)
{
	unsigned char	d[4];
	unsigned int	u;

	d[0] = (unsigned char)data[3];
	d[1] = (unsigned char)data[2];
	d[2] = (unsigned char)data[1];
	d[3] = (unsigned char)data[0];
	u = *((unsigned int *)d);
	return (u);
}

void			check_cor(char *buf, int n, char *fname)
{
	unsigned int	magic_num;
	unsigned int	prog_size;

	magic_num = data_to_uint(buf);
	prog_size = data_to_uint(buf + PROG_NAME_LENGTH + 8);
	if (magic_num != COREWAR_EXEC_MAGIC)
		ft_error2("Error : wrong file type : ", fname);
	if (!buf[4] || buf[PROG_NAME_LENGTH + 4])
		ft_error2("Error : invalid champion name : ", fname);
	if (!buf[PROG_NAME_LENGTH + 12]
		|| buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 12])
		ft_error2("Error : invalid comment : ", fname);
	if (n - sizeof(t_header) != prog_size)
		ft_error2("Error : wrong size for instruction block : ", fname);
}

int				is_valid_cor(char *path)
{
	int		fd;
	size_t	n;
	int		size;
	char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + CHAMP_MAX_SIZE];

	size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + CHAMP_MAX_SIZE;
	if ((fd = open(path, O_RDONLY)) < 0)
		ft_error2("Error : can't read source file ", path);
	n = read(fd, buf, size);
	close(fd);
	if (sizeof(t_header) > n)
		ft_error2("Error : file too small : ", path);
	check_cor(buf, n, path);
	return (1);
}

void			get_env2(t_env *env, char **argv, int argc)
{
	int	i;
	int num;

	i = 1;
	num = 0;
	while (i < argc && num < MAX_PLAYERS)
	{
		if (env->players[num].name)
			num++;
		else
		{
			if (!ft_strcmp(argv[i], "-v"))
				i++;
			if (!ft_strcmp(argv[i], "-dump"))
				i++;
			else if (!ft_strcmp(argv[i], "-n"))
				i += 2;
			else if (is_valid_cor(argv[i]))
				read_cor(env, num++, argv[i]);
			i++;
		}
	}
}

void			get_env(t_env *env, char **argv, int argc)
{
	int	i;
	int num;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-dump") && i < argc - 1)
			env->dump = ft_atoi(argv[++i]);
		if (!ft_strcmp(argv[i], "-n") && i < argc - 2)
		{
			num = ft_atoi(argv[++i]) - 1;
			if (env->players[num].name)
				ft_error("Error : two champions cannot have the same number");
			else if (is_valid_cor(argv[++i]))
				read_cor(env, num, argv[i]);
		}
		if (!ft_strcmp(argv[i], "-v"))
			env->ncurses = 1;
		i++;
	}
	get_env2(env, argv, argc);
	if (!(env->ncurses))
		env->run = 1;
}
