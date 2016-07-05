/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 13:41:43 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/25 19:04:17 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <limits.h>

typedef struct		s_flag
{
	int				nbprint;

	int				sharp;
	int				zero;
	int				moins;
	int				plus;
	int				space;
	int				width;
	int				precision;

	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
	char			type;
}					t_flag;

typedef struct		s_wchar
{
	unsigned int	value;
	unsigned int	size;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
}					t_wchar;

int					ft_printf(char *str, ...);
int					ft_afterpourcent(va_list ap, t_flag *tmp, char *str, int i);
t_flag				*ft_initialflag(t_flag *tmp);
int					ft_checkflag(va_list ap, t_flag *tmp, char *str, int i);
int					ft_checkflag2(t_flag *tmp, char *str, int i);
int					ft_checkoption(t_flag *tmp, char *str, int i);
int					ft_checkoptionsuite(t_flag *tmp, char *str, int i);
int					ft_checkwidth(t_flag *tmp, char *str, int i);
int					ft_checkprecision(t_flag *tmp, char *str, int i);
int					ft_checkmodif(t_flag *tmp, char *str, int i);
int					ft_checkh(t_flag *tmp, char *str, int i);
int					ft_checkl(t_flag *tmp, char *str, int i);
int					ft_checktype(t_flag *tmp, char *str, int i);
void				ft_printmodificator(t_flag *tmp, void *nbr);

void				ft_checkint(t_flag *tmp, va_list ap);
void				ft_checkintsuite(t_flag *tmp, int len, int lenprecision,
					void *nbr);
void				ft_printprecision(t_flag *tmp, int lenprecision);
int					ft_len(long long nbr);
int					ft_lenmodif(t_flag *tmp, void *nbr);
void				ft_printplus_spaceint(t_flag *tmp, int nbr);
void				ft_lookwidth(t_flag *tmp, int len);
void				ft_lookwidthsuite(t_flag *tmp);

void				ft_checkchar(t_flag *tmp, va_list ap);

void				ft_checkcmaj(t_flag *tmp, va_list ap);

void				ft_checkstr(t_flag *tmp, va_list ap);
void				ft_checkstrsuite(t_flag *tmp, char *str, int nbr);
void				ft_lookwidth2(t_flag *tmp, int nbr);
char				*ft_strprecision(char *str, int n);

void				ft_checksmaj(t_flag *tmp, va_list ap);
wchar_t				*ft_wstrdup(wchar_t *str);
size_t				ft_wstrlen(wchar_t *str);
int					ft_putwstr(wchar_t *str, t_flag *tmp, int prec);

void				ft_checkx(t_flag *tmp, va_list ap);
void				ft_checkxsuite(t_flag *tmp, int i, int j, char *str);
void				ft_lookwidthx(t_flag *tmp, int i);
char				*ft_toa_basemodif(t_flag *tmp, va_list ap, int base);

void				ft_checku(t_flag *tmp, va_list ap);
void				ft_tmpforu(t_flag *tmp);
void				ft_nbrneg(t_flag *tmp, int nbr);
int					ft_nbrpos(t_flag *tmp, int len);
void				ft_printu(t_flag *tmp, int nbr, size_t nbrz,
					unsigned char nbrhh);
void				ft_umoins(t_flag *tmp, int len);
void				ft_forz(t_flag *tmp, size_t nbr);
int					ft_lenuint(unsigned int max);
void				ft_modifmaj(t_flag *tmp);
int					ft_lenu(t_flag *tmp, int nbr, size_t nbrz,
					unsigned char nbrhh);

void				ft_checko(t_flag *tmp, va_list ap);
void				ft_checkosuite(t_flag *tmp, int i, char *str);
void				ft_lookwidtho(t_flag *tmp, int i);
void				ft_tmpforo(t_flag *tmp);

void				ft_checkp(t_flag *tmp, va_list ap);
void				ft_checkpsuite(t_flag *tmp, int i, unsigned long long nbr,
					char *ptr);

int					ft_putwchar(wchar_t c, t_flag *tmp, int prec);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putlnbr(long n);
void				ft_putllnbr(long long n);
void				ft_puthnbr(short n);
void				ft_puthhnbr(long n);
void				ft_putznbr(long long n);
void				ft_putjnbr(long long n);
void				ft_putnbruint(unsigned int max);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_lltoa_base(long long n, int base);
char				*ft_lltoa_basemaj(long long n, int base);
char				*ft_ulltoa_base(unsigned long long n, unsigned int base);
char				*ft_ulltoa_basemaj(unsigned long long n, unsigned int base);
char				*ft_ultoa_base(unsigned long n, unsigned int base);
char				*ft_ultoa_basemaj(unsigned long n, unsigned int base);
unsigned long		ft_ullenght(unsigned long long n, unsigned int base);
unsigned long		ft_ulenght(unsigned long n, unsigned int base);
unsigned int		size_bin(unsigned int i);

#endif
