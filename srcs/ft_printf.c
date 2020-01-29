/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 12:54:42 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 20:20:57 by csapt       ###    #+. /#+    ###.fr     */
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

int		ft_addflags(t_struct *flag, const char *fmt, int *x, va_list arg)
{
	if (fmt[*x] == '-')
		return (ft_printleftspace(fmt, x, flag, arg));
	else if (fmt[*x] == '.')
		return (ft_printprecision(fmt, x, flag, arg));
	else if (fmt[*x] == '*')
		return (ft_printwidth(flag, x, arg));
	else if (fmt[*x] > '0' && fmt[*x] <= '9')
		return (ft_printspace(fmt, x, flag));
	else if (fmt[*x] == '0')
		return (ft_printzero(x, flag));
	else
		return (-1);
}

int		ft_print_parse(const char *fmt, va_list arg, t_struct *flag)
{
	int x;
	int i;
	int temp;

	temp = 0;
	x = ft_gotoflags(fmt);
	i = 0;
	write(1, fmt, x);
	flag->write = flag->write + x;
	if (fmt[x] == '\0')
		return (0);
	x++;
	while (fmt[x])
	{
		while (temp != -1)
			temp = ft_addflags(flag, fmt, &x, arg);
		ft_printconvert(fmt, flag, arg, &x);
		temp = 0;
		ft_refreshstruct(flag);
		i = ft_gotoflags(fmt + x);
		write(1, fmt + x, i);
		flag->write = flag->write + i;
		x = x + i;
		if (fmt[x] == '%')
			x++;
	}
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	t_struct flag;

	va_start(arg, fmt);
	ft_initstruct(&flag);
	if (ft_print_parse(fmt, arg, &flag) == -1)
		return (-1);
	va_end(arg);
	return(flag.write);
}