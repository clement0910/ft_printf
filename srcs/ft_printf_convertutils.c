/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_convertutils.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 13:15:42 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 14:51:21 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_convert_snull(char **str, t_struct *flag)
{
	flag->snull = 1;
	*str = ft_strdup("(null)");
	return (6);
}

void	ft_convert_sutils(t_struct *flag, int len)
{
	if (flag->space > 0)
	{
		if (flag->precision > 0 && flag->precision < len)
			flag->space = flag->space - flag->precision;
		else if (flag->precision == 0)
			flag->space = flag->space;
		else
			flag->space = flag->space - len;
	}
	if (flag->nspace > 0)
	{
		if (flag->precision > 0 && flag->precision < len)
			flag->nspace = flag->nspace - flag->precision;
		else if (flag->precision == 0)
			flag->space = flag->space;
		else
			flag->nspace = flag->nspace - len;
	}
}

void	ft_convert_dutils(t_struct *flag, int len)
{
	if (flag->precision >= 0)
		flag->zero = 0;
	if (flag->space > 0)
	{
		flag->precision = (flag->precision > len) ? flag->precision : len;
		flag->space = flag->space - flag->precision;
	}
	if (flag->nspace > 0)
	{
		flag->precision = (flag->precision > len) ? flag->precision : len;
		flag->nspace = flag->nspace - flag->precision;
	}
	if (flag->precision > 0)
		flag->precision = flag->precision - len;
}

void	ft_convertdnegutils(t_struct *flag, long d)
{
	int len;

	d = -d;
	len = ft_ullintlen(d, "0123456789");
	ft_convert_dutils(flag, len);
	flag->space--;
	flag->nspace--;
	if (flag->space > 0 && flag->zero == 0)
		ft_multipleswrite(flag->space, ' ', flag);
	if (flag->space > 0 && flag->zero == 1)
	{
		ft_multipleswrite(1, '-', flag);
		ft_multipleswrite(flag->space, '0', flag);
	}
	else
		ft_multipleswrite(1, '-', flag);
	ft_multipleswrite(flag->precision, '0', flag);
	ft_putunsignednbr_fd(d, 1);
	flag->write = flag->write + len;
	ft_multipleswrite(flag->nspace, ' ', flag);
}
