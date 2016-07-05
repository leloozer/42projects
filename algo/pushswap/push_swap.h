/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:55:48 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/10 22:32:59 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct				s_elementlist
{
	int						number;
	struct s_elementlist	*next;
	struct s_elementlist	*prev;
}							t_elementlist;

typedef struct				s_reperelist
{
	int						len;
	t_elementlist			*first;
	t_elementlist			*last;
}							t_reperelist;

typedef struct				s_option
{
	int						afflist;
	int						nbr;
}							t_option;

int							ft_listinit(int argc, char **argv,
							t_option *opt);
int							ft_firstelemlist(t_reperelist *list_a,
							char *argv);
int							ft_pushfront(t_reperelist *list_a,
							char *argv);
t_reperelist				*ft_initial(t_reperelist *list);

int							ft_notint(char **argv, t_option *opt);
int							ft_error(char **argv);
int							ft_errornotint(char **argvi,
							t_option *opt);
void						ft_opt(t_reperelist *list_a, t_reperelist *list_b,
							t_option *opt);
t_reperelist				*ft_algo(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_check(t_reperelist *list_a);
int							ft_check2(t_reperelist *list_b);

int							ft_checkoption(char **argv, t_option *opt);
int							ft_printlist(t_reperelist *list_a,
							t_reperelist *list_b);
int							ft_printlist2(t_reperelist *list_b);

int							ft_sa(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_sb(t_reperelist *list_b,
							t_reperelist *list_a, t_option *opt);
int							ft_pa(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_pa2(t_reperelist *list_a,
							t_reperelist *list_b, t_elementlist *tmp,
							t_option *opt);
int							ft_pb(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_ra(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_rb(t_reperelist *list_b,
							t_reperelist *list_a, t_option *opt);
int							ft_rr(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_rra(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_rrb(t_reperelist *list_b,
							t_reperelist *list_a, t_option *opt);
int							ft_pb2(t_reperelist *list_b,
							t_reperelist *list_a, t_elementlist	*tmp,
							t_option *opt);
void						ft_algo2(t_reperelist *list_a,
							t_reperelist *list_b, t_option *opt);
int							ft_atoi(const char *nptr);
long long					ft_atoll(const char *str);
int							ft_strcmp(const char *s1, const char *s2);
void						ft_putnbr(int n);

#endif
