/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:10:16 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ncurses.h>
# include "libft/libft.h"
# include "op.h"

# define SCREEN_HEIGHT 68
# define SCREEN_WIDTH 197
# define SCREEN_STARTX 2
# define SCREEN_STARTY 2

# define HUD_HEIGHT 40
# define HUD_WIDTH 30
# define HUD_STARTX 198
# define HUD_STARTY 2

typedef struct			s_process
{
	unsigned char		reg[REG_NUMBER][REG_SIZE];
	size_t				pc;
	size_t				carry;
	size_t				cycles;
	size_t				live;
	size_t				start_pc;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef struct			s_champ
{
	size_t				number;
	char				*name;
	char				*comment;
	unsigned char		*data;
	size_t				pc;
	size_t				size;
	size_t				live;
}						t_champ;

typedef struct			s_env
{
	WINDOW				*my_win;
	WINDOW				*my_screen;
	WINDOW				*my_hud;
	size_t				max_cycles;
	size_t				die;
	size_t				live;
	size_t				last_live;
	size_t				rate;
	size_t				run;
	int					dump;
	int					ncurses;
	unsigned char		color[MEM_SIZE];
	unsigned char		mem[MEM_SIZE];
	struct s_champ		players[MAX_PLAYERS];
	struct s_process	*p_list;
}						t_env;

t_op					g_op_tab[20];
void					(*g_op_exec[19])(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);

void					ft_error2(char *msg1, char *msg2);
void					ft_error(char *msg);
void					check_errors(int argc, char **argv);
void					init_env(t_env *env);
void					read_cor(t_env *env, int num, char *fname);
void					get_env(t_env *env, char **argv, int argc);
void					put_hex(unsigned char c);
void					get_hexa(char tab[3], t_env *env, int i);
void					hexdump(unsigned char *data, size_t size);
void					add_process(size_t pc, size_t num, t_env *env);
void					set_processes(t_env *env);
void					set_vm(t_env *env);

unsigned char			proper_size(unsigned char a, size_t op);
unsigned char			get_offset(unsigned char size[3]);
int						valid_op(unsigned char op);
size_t					arg_size(unsigned char type);
void					load_a(unsigned char a[4], t_env *env,
						size_t pos, size_t size);
void					load_args(unsigned char arg[4][4],
						t_env *env, size_t pc);
void					load_args2(unsigned char arg[4][4],
						t_env *env, size_t pc);
void					select_op(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t op);
void					exec_op(t_env *env, t_process *p);
void					del_process(t_process **p);
void					decr_die(t_env *env);
void					remove_dead(t_env *env);
size_t					count_living(t_env *env);
size_t					exec(t_env *env, size_t i);
void					print_winner(t_env *env);
void					cycle_rate(t_env *env, int *input, int count);
void					run_processes(t_env *env);

void					set_color(void);
void					init_ncurses(t_env *env);
void					refresh_ncurses(t_env *env);
void					reset_color(t_env *env, int i);
void					pc_color(t_env *env, int i, int x, int y);
void					draw_borders(WINDOW *screen);
char					*count_processes(t_process *p);
int						print_champs(t_env *env);
void					print_infos(t_env *env, int i);
void					print_hud(t_env *env, int count);
void					print_mem(t_env *env, int count);

size_t					mod_mem(size_t n);
size_t					mod_idx(size_t n, t_process *p, size_t s);
int						is_reg(size_t reg);
void					r_copy(unsigned char *src,
						unsigned char *dst, size_t size);
void					reg_copy(unsigned char *src,
						unsigned char *reg, size_t size);
size_t					r_to_n(unsigned char *tab, size_t size);
void					n_to_r(unsigned char *tab, size_t size, size_t n);
size_t					mem_to_n(unsigned char *mem, size_t start, size_t size);
void					n_to_mem(t_env *env, t_process *p,
						size_t start, size_t n);
size_t					mod_idx2(unsigned int a2, unsigned int a3, t_process *p);

void					op_live(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_ld(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_st(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_add(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_sub(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_and(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_or(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_xor(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_zjmp(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_ldi(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_sti(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_fork(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_lld(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_lldi(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_lfork(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_aff(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_mul(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_div(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);
void					op_mod(t_env *env, t_process *p,
						unsigned char arg[4][4], size_t *t);

#endif
