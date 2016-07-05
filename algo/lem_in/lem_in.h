/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:05:02 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 17:20:55 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "ft_printf/printf.h"

typedef struct		s_anthill
{
	struct s_room	*start;
	struct s_room	*end;
}					t_anthill;

typedef struct		s_room
{
	int				y;
	int				x;
	int				flag;
	int				fils;
	char			*name;
	struct s_room	*next[1000];
	struct s_room	*prev[1000];
}					t_room;

typedef struct		s_queue
{
	int				ok;
	struct s_room	*output;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_tube
{
	char			*t_1;
	char			*t_2;
	int				nbr;
	int				use;
	struct s_tube	*next;
	struct s_tube	*prev;
}					t_tube;

typedef struct		s_param
{
	int				antsnbr;
	int				start;
	int				end;
	t_room			*tab;
	t_tube			*tub;
}					t_param;

int					get_next_line(int const fd, char **line);
int					ft_parse(t_param *env, t_anthill *anthill);
int					ft_read_line(char *line, t_param *env, t_anthill *anthill);
int					ft_read_line_suite(char *line, t_param *env,
					t_anthill *anthill, int retroom);
void				ft_initialenv(t_param *env);
void				ft_initialanthill(t_anthill *anthill);
t_room				*ft_initroom(t_room *room);
int					ft_checkants(char *line, t_param *env);
int					ft_checkroom(char *line, t_param *env);
int					ft_checkcom(char *line, t_param *env);
int					ft_checktube(char *line, t_param *env, t_anthill *anthill);
int					ft_counttab(char **tab);
int					ft_isnum(char *str);
int					ft_checkroomname(char **room_name);
int					ft_checkpipename(char **pipe, t_param *env,
					t_anthill *anthill);
void				ft_errorandexit(int x);
int					ft_anthillstartend(char *line, t_param *env,
					t_anthill *anthill);
void				ft_go_anthill_start(char **room, t_anthill *anthill);
void				ft_go_anthill_end(char **room, t_anthill *anthill);
void				ft_firsttabenv(char **room, t_param *env);
void				ft_pushbacktabenv(char **room, t_param *env);
void				ft_firsttubenv(char **pipe, t_param *env);
void				ft_pushbacktubenv(char **pipe, t_param *env);
int					ft_checkusepipe(t_param *env, t_room *start,
					t_queue *queue);
void				ft_connect(t_param *env, t_anthill *anthill,
					t_queue *queue);
t_room				*ft_connectrecursive(t_param *env, t_room *start,
					t_anthill *anthill, t_queue *queue);
void				ft_endrecursive(t_param *env, t_anthill *anthill,
					t_room *start, t_tube *tmp);
t_room				*ft_anthillson(t_param *env, char *t_1, char *t_2,
					t_room *start);
t_room				*ft_inanthill(t_room *forcpy, t_room *start);
void				ft_inanthillend(t_anthill *anthill, t_room *start);
t_room				*ft_anthillstartnext(t_room *start, t_queue *queue);
t_room				*ft_anthillstartprev(t_room *start);

void				ft_initqueue(t_queue *queue);
t_queue				*ft_supproutput(t_queue *queue);
void				ft_addinput(t_queue *queue, t_room *room);
void				ft_firstqueue(t_queue *queue, t_room *room);

void				ft_freeanthill(t_anthill *anthill);
void				ft_freequeue(t_queue *queue);
void				ft_freeenv(t_param *env);

char				**ft_strsplit(char const *s, char c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
long long			ft_atoll(const char *str);
int					ft_strsearch(const char *s, char c);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_goodroad(t_param *env, t_anthill *anthill);
int					ft_goodroadsuite(t_param *env, t_anthill *anthill);
void				ft_print(t_param *env, t_anthill *anthill);
int					ft_check_flag(t_anthill *anthill);

#endif
