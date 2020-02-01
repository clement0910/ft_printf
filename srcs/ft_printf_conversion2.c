/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion2.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 12:22:16 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 15:46:46 by csapt       ###    #+. /#+    ###.fr     */
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

int		findindex(char element)
{
	int		x;
	char	tab[9];

	x = 0;
	tab[0] = 's';
	tab[1] = 'd';
	tab[2] = 'c';
	tab[3] = 'p';
	tab[4] = 'u';
	tab[5] = 'x';
	tab[6] = 'X';
	tab[7] = 'i';
	tab[8] = 0;
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

void	ft_printfunc(char *fmt, t_struct *flag, va_list arg, int *x)
{
	void	(*tabfunction[8])(t_struct *, va_list);
	int		index;

	tabfunction[0] = ft_convert_s;
	tabfunction[1] = ft_convert_d;
	tabfunction[2] = ft_convert_c;
	tabfunction[3] = ft_convert_p;
	tabfunction[4] = ft_convert_u;
	tabfunction[5] = ft_convert_x;
	tabfunction[6] = ft_convert_xmaj;
	tabfunction[7] = ft_convert_d;
	index = findindex(fmt[*x]);
	if (index == -1)
		return ;
	if (index == -2)
	{
		ft_convert_percent(flag);
		(*x)++;
		return ;
	}
	(*tabfunction[index])(flag, arg);
	(*x)++;
}
