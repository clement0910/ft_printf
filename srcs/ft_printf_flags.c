/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_flags.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 09:38:47 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 10:11:51 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printleftspace(const char *fmt, int *x, t_struct *flag)
{
	*x++;
	flag->nspace = 0;
	while (fmt[*x] >= '0' && fmt[*x] <= '9')
	{
		flag->nspace = (flag->nspace * 10) + (fmt[*x] - '0');
		*x++;
	}
	//mettre dans flag->write
	return (1);
}

int		ft_printprecision(const char *fmt, int *x, t_struct *flag, va_list arg)
{
	*x++;
	if (fmt[*x] == '*')
	{
		flag->precision = va_arg(arg, int);
		*x++;
		return (x);	
	}
	flag->precision = 0;
	while (fmt[*x] >= '0' && fmt[*x] <= '9') // répétitif donc peut-etre remplacer par atoi modifier
	{
		flag->precision = (flag->precision * 10) + (fmt[*x] - '0');
		*x++;
	}
	return (1);
}

int		ft_printwidth(t_struct *flag, int *x, va_list arg)
{
	flag->widthnbr = va_arg(arg, int);
	*x++;
	if (flag->widthnbr < 0)
		flag->nspace = flag->widthnbr;
	return (1);
}

int		ft_printspace(const char *fmt, int *x, t_struct *flag)
{
	*x++;
	flag->space = 0;
	while (fmt[*x] >= '0' && fmt[*x] <= '9')
	{
		flag->space = (flag->space * 10) + (fmt[x] - '0');
		*x++;
	}
	return (1);
}

int		ft_printzero(int *x, t_struct *flag)
{
	*x++;
	flag->zero = 1;
	return (1);
}