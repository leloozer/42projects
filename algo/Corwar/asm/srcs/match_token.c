/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:44:36 by ndauteui          #+#    #+#             */
/*   Updated: 2016/03/28 18:37:06 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_get_param_type(char *str)
{
	if (str[0] == 'r' && ft_strlen(str) <= 3
		&& (ft_isdigit_string(str + 1) == 1)
		&& (ft_atoi(str + 1) <= 16 && (ft_atoi(str + 1) >= 1)))
		return (PARAM_REG);
	if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR
		&& ft_isalnum_string(str + 1, LABEL_CHAR, '_', -1) == 1)
		return (PARAM_LABEL_DIR);
	else if (str[0] == LABEL_CHAR &&
		ft_isalnum_string(str, LABEL_CHAR, '_', -1) == 1)
		return (PARAM_LABEL_IND);
	if (str[0] == DIRECT_CHAR && ft_isdigit_string(str + 1) == 1)
		return (PARAM_DIR);
	else if (ft_isdigit_string(str) == 1)
		return (PARAM_IND);
	ft_error(ft_strjoin("Invalid parameter: ", str));
	return (-1);
}

t_tlist		*ft_spe(t_tlist *list)
{
	t_tlist	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->has_ocp = ft_get_op_by_name(tmp->content)->has_ocp;
	tmp->weight = 1 + tmp->has_ocp;
	return (list);
}

t_tlist		*ft_get_weight(t_tlist *list, int type)
{
	t_tlist	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->type == PARAM_REG)
		tmp->weight = 1;
	else if (tmp->type == PARAM_IND || tmp->type == PARAM_LABEL_IND)
		tmp->weight = 2;
	else if ((tmp->type == PARAM_DIR || tmp->type == PARAM_LABEL_DIR)
		&& type == INSTRUCTION_SPE)
		tmp->weight = 2;
	else if (tmp->type == PARAM_DIR || tmp->type == PARAM_LABEL_DIR)
		tmp->weight = 4;
	return (list);
}

t_tlist		*ft_check_line(char **split, t_tlist *tlist, int j)
{
	int		type;
	int		i;
	char	**split2;

	i = 0;
	if ((type = ft_check_instruction(split[j])) != -1)
		tlist = ft_spe(ft_create_and_add_telem(tlist, split[j], type));
	else
		return (ft_error("unknown instruction"));
	if (split[i][(ft_strlen(split[i]) - 1)] == LABEL_CHAR)
		split2 = ft_strsplit(ft_implode(split + 2), SEPARATOR_CHAR);
	else
		split2 = ft_strsplit(ft_implode(split + 1), SEPARATOR_CHAR);
	i = 0;
	while (split2[i])
	{
		if (ft_get_param_type(split2[i]) != 1)
			tlist = ft_get_weight(ft_create_and_add_telem(tlist,
			ft_strtrim(split2[i]), ft_get_param_type(split2[i])), type);
		i++;
	}
	return (tlist);
}

t_tlist		*ft_match_token(char *str, char **split, t_tlist *tlist, int i)
{
	if (ft_strequ(str, "\n") == 1)
		return (ft_create_and_add_telem(tlist, "", ENDL));
	else if (ft_strequ(str, ".name") == 1)
		return (ft_check_name(split, tlist, i));
	else if (ft_strequ(str, ".comment") == 1)
		return (ft_check_description(split, tlist, i));
	else if (split[i][(ft_strlen(split[i]) - 1)] == ':')
		return (ft_check_label(str, tlist));
	else if ((tlist = ft_check_line(split, tlist, i)) != NULL)
		return (tlist);
	return (ft_error("unknown token"));
}
