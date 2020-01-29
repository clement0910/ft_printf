/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 10:15:14 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 20:21:28 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(t_struct *flag, va_list arg)
{
	char *str;
	int len;

	str = va_arg(arg, char *);
	if (str == NULL)  //Peux mettre len dans une fonction
		len = ft_convert_snull(&str, flag);
	else
		len = (int)ft_strlen(str);
	ft_convert_sutils(flag, len);
	if (flag->precision >= 0) //Peux mettre aussi dans fonction
	{
		if (flag->precision == 0)
			len = 0;
		else
			len = (flag->precision > len) ? len : flag->precision;
	}
	ft_multipleswrite(flag->space, ' ', flag);
	write(1, str, len);
	flag->write = flag->write + len; 
	ft_multipleswrite(flag->nspace, ' ', flag);
	if (flag->snull == 1)
		free(str);
}

void	ft_convert_d(t_struct *flag, va_list arg)
{
	int d;
	int len;

	d = va_arg(arg, int);
	len = ft_intlen(d); //peux mettre le check avant comme ca pas besoin de rajouter condition si ==0 dans fonction intlen
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	ft_convert_dutils(flag, len);
	if (d < 0)
	{
		flag->space--;
		flag->nspace--; //soit l'un soit l'autre
	}
	if (flag->space > 0 && flag->zero == 0) 
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
	{
		if (d < 0)
			ft_multipleswrite(1, '-', flag);
		ft_multipleswrite(flag->space, '0', flag);
	}
	else
	{
		if (d < 0)
			ft_multipleswrite(1, '-', flag);
	}
	if (d < 0)
		d = d * -1;
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putnbr_fd(d, 1);
	flag->write = flag->write + len; 
	ft_multipleswrite(flag->nspace, ' ', flag); //Check flag->zero ?	
}

void	ft_convert_c(t_struct *flag, va_list arg)
{
	unsigned int c;

	c = (unsigned char)va_arg(arg, int);
	ft_multipleswrite(flag->space - 1, ' ', flag);
	write(1, &c, 1);
	flag->write++;
	ft_multipleswrite(flag->nspace - 1, ' ', flag);
}

void	ft_convert_p(t_struct *flag, va_list arg)
{
	unsigned long long int ptr;
	char *str;
	int len;

	ptr = (unsigned long int)va_arg(arg, void *);
	str = ft_ulltoa_base(ptr, "0123456789abcdef"); //unsigned long long int
	len = ft_strlen(str);
	ft_multipleswrite(flag->space - (len + 2), ' ', flag);
	write(1, "0x", 2);
	write(1, str, len);
	flag->write = flag->write + (len + 2);
	ft_multipleswrite(flag->nspace - (len + 2), ' ', flag);
	free(str);
}

void	ft_convert_u(t_struct *flag, va_list arg)
{
	unsigned int d;
	int len;

	d = va_arg(arg, unsigned int);
	if (flag->precision == 0 && d == 0)
	{
		ft_multipleswrite(flag->space, ' ', flag);
		ft_multipleswrite(flag->nspace, ' ', flag);
		return ;
	}
	len = ft_uintlen(d);
	ft_convert_dutils(flag, len);
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
		ft_multipleswrite(flag->space, '0', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putnbrunsigned(d);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag); //Check flag->zero ?
}

void	ft_convert_x(t_struct *flag, va_list arg)
{
	unsigned int d;
	int len;
	char *str;

	d = va_arg(arg, unsigned int);
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
	unsigned int d;
	int len;
	char *str;

	d = va_arg(arg, unsigned int);
	str = ft_utoa_base(d, "0123465789ABCDEF");
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
	void (*tabFunction[8])(t_struct *,va_list) = {ft_convert_s, 
	ft_convert_d, ft_convert_c, ft_convert_p, ft_convert_u, ft_convert_x,
	ft_convert_xmaj, ft_convert_d};
	char tabIndex[9] = {'s', 'd', 'c', 'p', 'u', 'x', 'X', 'i', 0};
	int index;

	index = findindex(tabIndex, fmt[*x]);
	if (index == -1)
		return ;
	if (index == -2)
	{
		ft_convert_percent(flag);
		(*x)++;
		return;
	}
	(*tabFunction[index]) (flag, arg);
	(*x)++;
}