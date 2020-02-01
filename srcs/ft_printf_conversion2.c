/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion2.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 12:22:16 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 12:38:06 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_x(t_struct *flag, va_list arg)
{
	unsigned int	d;
	int				len;
	char			*str;

	d = va_arg(arg, unsigned int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_utoa_base(d, "0123456789abcdef");
	len = ft_strlen(str);
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	write(1, str, len);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
	free(str);
}

void	ft_convert_xmaj(t_struct *flag, va_list arg)
{
	unsigned int	d;
	int				len;
	char			*str;

	d = va_arg(arg, unsigned int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	str = ft_utoa_base(d, "0123456789ABCDEF");
	len = ft_strlen(str);
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	write(1, str, len);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
	free(str);
}

void	ft_convert_percent(t_struct *flag)
{
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space - 1, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space - 1, '0', flag);
	write(1, "%", 1);
	flag->write++;
	ft_multipleswrite(flag->nspace - 1, ' ', flag);
}

int		findindex(char *tab, char element)
{
	int x;

	x = 0;
	while (tab[x])
	{
		if (tab[x] == element)
			return (x);
		if (element == '%')
			return (-2);
		x++;
	}
	return (-1);
}

void	ft_printconvert(const char *fmt, t_struct *flag, va_list arg, int *x)
{
	void (*tabFunction[8])(t_struct *, va_list) = {ft_convert_s,
	ft_convert_d, ft_convert_c, ft_convert_p, ft_convert_u, ft_convert_x,
	ft_convert_xmaj, ft_convert_d};
	char tabIndex[9] = 	{'s', 'd', 'c', 'p', 'u', 'x', 'X', 'i', 0};
	int index;

	index = findindex(tabIndex, fmt[*x]);
	if (index == -1)
		return ;
	if (index == -2)
	{
		ft_convert_percent(flag);
		(*x)++;
		return ;
	}
	(*tabFunction[index])(flag, arg);
	(*x)++;
}
