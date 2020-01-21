/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_conversion.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 10:15:14 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:48:21 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(t_struct *flag, va_list arg)
{
	char *str;
	int len;

	str = va_arg(arg, char *);
	if (str == NULL) //Peux mettre len dans une fonction
		len = ft_convert_snull(str, flag);
	else
		len = (int)ft_strlen(str);
	ft_convert_sutils(flag, len);
	if (flag->precision >= 0) //Peux mettre aussi dans fonction
	{
		if (flag->precision >= 0)
			len = 0;
		else
			len = (flag->precision > len) ? len : flag->precision;
	}
	ft_multipleswrite(flag->space, ' ');
	write(1, str, len);
	ft_multipleswrite(flag->nspace, ' ');
	if (flag->snull == 1)
		free(str);
}

void	ft_convert_d(t_struct *flag, va_list arg)
{
	int d;
	int len;

	d = va_arg(arg, int);
	len = ft_intlen(d);
	if (flag->precision == 0 && d == 0)
		return ;
	ft_convert_dutils(flag, len);
	if (d < 0)
		flag->space--;
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ');
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0');
	if (d < 0)
		write(1, "-", 1);
	ft_multipleswrite(flag->precision, '0');
	if (d < 0) //peux remplacer par fonction
		d = d * -1;
	ft_putnbr_fd(d, 1);
	ft_multipleswrite(flag->nspace, ' '); //Check flag->zero ?	
}

void	ft_convert_c(t_struct *flag, va_list arg)
{
	unsigned int c;

	c = (unsigned char)va_arg(arg, int);
	ft_multipleswrite(flag->space--, ' ');
	write(1, &c, 1);
	ft_multipleswrite(flag->space--, ' ');
}

void	ft_convert_p(t_struct *flag, va_list arg)
{
	unsigned int ptr;
	char *str;
	int len;

	ptr = (unsigned int)va_arg(arg, void *);
	str = ft_utoa_base(ptr, "0123456789abcdef");
	len = ft_strlen(str);
	ft_multipleswrite(flag->space - (len + 2), ' ');
	write(1, "0x", 2);
	write(1, str, len);
	ft_multipleswrite(flag->nspace - (len + 2), ' ');
	free(str);
}

void	ft_convert_u(t_struct *flag, va_list arg)
{
	unsigned int d;
	int len;

	d = va_arg(arg, unsigned int);
	if (flag->precision == 0 && d == 0)
		return ;
	len = ft_uintlen(d);
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ');
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0');
	ft_multipleswrite(flag->precision, '0');
	ft_putnbrunsigned(d);
	ft_multipleswrite(flag->nspace, ' '); //Check flag->zero ?
}

void	ft_convert_x(t_struct *flag, va_list arg)
{
	unsigned int d;
	int len;
	char *str;

	d = va_arg(arg, unsigned int);
	str = ft_utoa_base(d, "0123465789abcdef");
	len = ft_strlen(str);
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ');
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0');
	ft_multipleswrite(flag->precision, '0');
	write(1, str, len);
	ft_multipleswrite(flag->nspace, ' ');
	free(str);
}

void	ft_convert_xmaj(t_struct *flag, va_list arg)
{
	unsigned int d;
	int len;
	char *str;

	d = va_arg(arg, unsigned int);
	str = ft_utoa_base(d, "0123465789abcdef");
	len = ft_strlen(str);
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ');
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0');
	ft_multipleswrite(flag->precision, '0');
	write(1, str, len);
	ft_multipleswrite(flag->nspace, ' ');
	free(str);
}

void	ft_convert_percent(t_struct *flag)
{
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space - 1, ' ');
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space - 1, '0');
	write(1, "%", 1);
	ft_multipleswrite(flag->nspace - 1, ' ');	
}

int		findindex(char *tab, char element)
{
	int x;

	x = 0;
	while (tab[x])
	{
		if (tab[x] == element)
			return (x);
		if (tab[x] == '%')
			return (-2);
		x++;
	}
	return (-1);
}

void	ft_printconvert(const char *fmt, t_struct *flag, va_list arg, int *x)
{
	void (*tabFunction[7])(t_struct *,va_list *) = {ft_convert_s, 
	ft_convert_d, ft_convert_c, ft_convert_p, ft_convert_u, ft_convert_x,
	ft_convert_xmaj};
	char tabIndex[8] = {'s', 'd', 'c', 'p', 'u', 'x', 'X', 0};
	int index;

	index = findindex(tabIndex, fmt[*x]);
	if (index == -1)
		return ;
	if (index == -2)
	{
		ft_convert_percent(flag);
		*x++;
		return;
	}
	(*tabFunction[index]) (flag, arg);
	*x++;
}