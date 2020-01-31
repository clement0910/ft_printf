
#ifndef _LIBFTPRINTF_H_
# define _LIBFTPRINTF_H_
# include "../libft/libft.h"
# include <inttypes.h> // For 1 bits int
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> //For Test Only

int						ft_printf(const char *format, ...)
						 __attribute__((format(printf,1,2)));

typedef struct	s_struct //peut opti ca 
{
	int widthnbr;
	int precision;
	int	nspace;
	int space;
	int write;
	uint8_t snull:1;
	uint8_t zero:1;
}				t_struct;

int		ft_printleftspace(const char *fmt, int *x, t_struct *flag, va_list arg);
int		ft_printprecision(const char *fmt, int *x, t_struct *flag, va_list arg);
int		ft_printwidth(t_struct *flag, int *x, va_list arg);
int		ft_printspace(const char *fmt, int *x, t_struct *flag);
int		ft_printzero(int *x, t_struct *flag);
void	ft_convert_s(t_struct *flag, va_list arg);
void	ft_convert_d(t_struct *flag, va_list arg);
void	ft_convert_c(t_struct *flag, va_list arg);
void	ft_convert_p(t_struct *flag, va_list arg);
void	ft_convert_u(t_struct *flag, va_list arg);
void	ft_convert_x(t_struct *flag, va_list arg);
void	ft_convert_xmaj(t_struct *flag, va_list arg);
void	ft_convert_percent(t_struct *flag);
int		findindex(char *tab, char element);
void	ft_printconvert(const char *fmt, t_struct *flag, va_list arg, int *x);

void	ft_multipleswrite(int x, char c, t_struct *flag);
int		ft_intlen(int x);
int     ft_howmanymalloc(unsigned long long int nbr, char *base);
char    *ft_ulltoa_base(unsigned long long int nbr, char *base);
char    *ft_utoa_base(unsigned int nbr, char *base);
int		ft_uintlen(unsigned int t);

int		ft_gotoflags(const char *fmt);
int		ft_addflags(t_struct *flag, const char *fmt, int *x, va_list arg);
int		ft_print_parse(const char *fmt, va_list arg, t_struct *flag);

int     ft_convert_snull(char **str, t_struct *flag);
void    ft_convert_sutils(t_struct *flag, int len);
void	ft_convert_dutils(t_struct *flag, int len);

void    ft_putnbrunsigned(unsigned int x);

void       ft_initstruct(t_struct *flag);
void       ft_refreshstruct(t_struct *flag);

char 	*ft_utoa_zero(void);

#endif