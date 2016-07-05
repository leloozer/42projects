/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:17:54 by ndauteui          #+#    #+#             */
/*   Updated: 2016/03/28 19:00:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_tlist	*ft_check_description(char **split, t_tlist *tlist, int j)
{
	int		i;

	i = 1;
	if (tlist && tlist->next && tlist->next->type == DESCRIPTION)
		return (ft_error("Syntax error: comment already given"));
	if (!split[1])
		return (ft_error("Syntax error: Missing description"));
	if (split && split[1] && split[1][0] != '"')
		return (ft_error("Syntax error on line 2: Missing '\"'\
		before comment"));
	if (ft_strchr(split[i] + 1, '"') != NULL)
		return (ft_create_and_add_telem(tlist,
		ft_get_string(split, ft_implode(split), DESCRIPTION, j), DESCRIPTION));
		i += 1;
	while (split[i])
	{
		if (ft_strchr(split[i], '"') != NULL)
			return (ft_create_and_add_telem(tlist, ft_get_string(split,
			ft_implode(split), DESCRIPTION, j), DESCRIPTION));
			i++;
	}
	return (ft_error("Syntax error on line 2: Missing '\"' after comment"));
}

t_tlist	*ft_check_name(char **split, t_tlist *tlist, int j)
{
	int		i;

	i = 1;
	if (tlist && tlist->type == NAME)
		return (ft_error("Syntax error: name already given"));
	if (!split[1])
		return (ft_error("Syntax error: Missing name"));
	if (split && split[1] && split[1][0] != '"')
		return (ft_error("Syntax error on line 1: Missing '\"' before name"));
	if (split[i] && ft_strchr(split[i] + 1, '"') != NULL)
		return (ft_create_and_add_telem(tlist, ft_get_string(split,
			ft_strsub(split[i], 1, ft_strlen(split[i]) - 2), NAME, j), NAME));
		i += 1;
	while (split[i])
	{
		if (ft_strchr(split[i], '"') != NULL)
			return (ft_create_and_add_telem(tlist,
			ft_get_string(split, ft_implode(split), NAME, j), NAME));
			i++;
	}
	return (ft_error("Syntax error on line 1: Missing '\"' after name"));
}

t_tlist	*ft_check_label(char *str, t_tlist *tlist)
{
	if (ft_isalnum_string(ft_strsub(str, 0, ft_strlen(str) - 2),
		-1, '_', -1) == 1)
		return (ft_create_and_add_telem(tlist, ft_strsub(str, 0, ft_strlen(str)
		- 1), LABEL));
		return (ft_error("unknown token"));
}

int		ft_check_instruction(char *str)
{
	t_op	*infos;

	if (ft_isalnum_string(str, SEPARATOR_CHAR, DIRECT_CHAR, LABEL_CHAR) != 1)
		return (-1);
	if ((infos = ft_get_op_by_name(str)))
	{
		if (infos->code >= 9 && infos->code <= 15)
			return (INSTRUCTION_SPE);
		else
			return (INSTRUCTION);
	}
	return (-1);
}
