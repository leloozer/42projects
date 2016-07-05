/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:25:27 by ndauteui          #+#    #+#             */
/*   Updated: 2016/04/08 16:11:21 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*ft_get_string(char **split, char *str, int type, int i)
{
	int		j;
	char	**split2;

	j = 1;
	(void)str;
	if (type != DESCRIPTION && type != NAME)
		return (split[i]);
	split2 = ft_strsplit(ft_implode_c(split, " "), '"');
	return (ft_strtrim(split2[1]));
}

void		ft_check_file_extension(char *file_name, t_file *file)
{
	char	*rev;

	rev = ft_strrev(file_name);
	if (rev[0] != 's' || rev[1] != '.')
		ft_errorandexit(1);
	file->name = ft_strdup(rev);
	free(rev);
}

int			ft_get_last_item_type(t_tlist *tlist)
{
	t_tlist		*tmp;

	tmp = tlist;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp->type);
}

t_tlist		*ft_lex(char *line, t_tlist *tlist)
{
	char	**split;
	int		i;
	int		last_type;

	split = ft_strsplit_double(ft_strtrim_comment(line), ' ', '\t');
	i = 0;
	while (split[i])
	{
		if (split[i][0] == COMMENT_CHAR || split[i][0] == ';')
			break ;
		tlist = ft_match_token(split[i], split, tlist, i);
		last_type = ft_get_last_item_type(tlist);
		if (last_type != LABEL)
			break ;
		i++;
	}
	tlist = ft_match_token("\n", split, tlist, i);
	return (tlist);
}

t_tlist		*ft_lexer(char *file_name, t_tlist *token_list, t_file *file)
{
	int		fd;
	char	*line;
	int		lines;

	token_list = NULL;
	lines = 0;
	ft_check_file_extension(file_name, file);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_errorandexit(2);
	while ((get_next_line(fd, &line)) == 1)
	{
		token_list = ft_lex(line, token_list);
		free(line);
		lines++;
	}
	if (lines <= 2)
		ft_error("parse error");
	if (ft_check_params(token_list) == 0)
		ft_error("parse error");
	token_list = ft_set_addresses(token_list);
	token_list = ft_remove_labels(token_list);
	return (token_list);
}
