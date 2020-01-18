/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 12:54:42 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 20:20:40 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_gotoflags(const char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int		ft_print_parse(const char *fmt, va_list arg, t_struct *flag)
{
	int x;
	int i;
	int temp;

	x = ft_gotoflags(fmt);
	i = 0;
	write(1, fmt, x);
	while (fmt[x])
	{
		while (temp != -1)
		{
			temp = ft_addflags();
		}
		ft_convert();
		temp = 0;
		ft_memset((void*)&flag, -1, sizeof(flag));
		i = ft_gotoflags(fmt);
		write(1, fmt + x, i);
		x = x + i;
	}
}
int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	t_struct flag;

	va_start(arg, fmt);
	ft_memset((void*)&flag, -1, sizeof(t_struct));
	if (ft_print_parse(fmt, arg, &flag) == -1)
		return (-1);
	va_end(arg);
	return(flag.write);
}