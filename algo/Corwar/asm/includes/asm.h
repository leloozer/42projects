/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:17:13 by mszczesn          #+#    #+#             */
/*   Updated: 2016/04/01 13:14:59 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "../ft_printf/printf.h"
# include "../libft/libft.h"
# include "op.h"

# define NAME 1
# define DESCRIPTION 2
# define LABEL 3
# define INSTRUCTION 4
# define INSTRUCTION_SPE 5
# define PARAM_LABEL_DIR 6
# define PARAM_REG 7
# define PARAM_DIR 8
# define PARAM_IND 9
# define PARAM_LABEL_IND 10
# define ENDL 11
# define COMMENT 12
# define NO_NEED 13
# define SIZE 14

typedef struct			s_tlist
{
	int					type;
	char				*content;
	int					has_ocp;
	int					addr;
	int					weight;
	struct s_tlist		*next;
	struct s_tlist		*prev;
}						t_tlist;

typedef struct			s_file
{
	char				*name;
	char				*namechamp;
	char				*comchamp;
	int					fd;
	unsigned long int	size;
	int					instruc_spe;
	char				*content;
}						t_file;

void					ft_errorandexit(int x);
void					ft_parser(char *str);
t_tlist					*ft_error(char *msg);
char					*ft_implode(char **split);
char					*ft_implode_c(char **split, char *c);
char					*ft_strtrim_comment(char *str);
int						ft_isalnum_string(char *str, char a, char b, char c);
int						ft_isdigit_string(char *str);
t_tlist					*ft_lexer(char *str, t_tlist *token_list, t_file *file);
void					ft_print_tlist(t_tlist *tlist);
t_tlist					*ft_create_and_add_telem(t_tlist *list, char *content,
						int type);
t_tlist					*ft_create_telem(char *content, int type);
t_tlist					*ft_match_token(char *str, char **split, t_tlist *list,
						int i);
char					*ft_get_string(char **split, char *str, int type,
						int i);
char					*ft_implode(char **split);
t_tlist					*ft_check_description(char **split, t_tlist *tlist,
						int j);
t_tlist					*ft_check_name(char **split, t_tlist *tlist, int j);
t_tlist					*ft_check_label(char *str, t_tlist *tlist);
int						ft_check_instruction(char *str);
t_tlist					*ft_set_addresses(t_tlist *tlist);
t_tlist					*ft_remove_labels(t_tlist *tlist);
int						ft_check_params(t_tlist *tlist);
t_op					*ft_get_op_tab(void);
t_op					*ft_get_op_by_name(char *name);
t_file					*ft_initfile(t_file *file);
t_file					*ft_createfile(t_file *file);
t_file					*ft_gotohexa(t_tlist *token_list, t_file *file);
t_tlist					*ft_opcode(t_tlist *token_list, t_file *file);
unsigned int			ft_ocptowrite2(t_tlist *tmp, unsigned int ocp);
void					ft_printinstruc(t_tlist *tmp, t_file *file);
unsigned int			ft_rev_uint(unsigned int n);
unsigned short int		ft_rev_usint(unsigned short int n);
int						ft_check_prev_exists(t_tlist *tlist, char *s);
int						ft_check_next_exists(t_tlist *tlist, char *s);

#endif
