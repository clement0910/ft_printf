
#ifndef _LIBFTPRINTF_H_
# define _LIBFTPRINTF_H_
# include "../libft/libft.h"
# include <inttypes.h> // For 1 bits int
# include <stdarg.h>
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
	uint8_t zero:1;
}				t_struct;

#endif