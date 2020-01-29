/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_convertutils.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 13:15:42 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 20:14:58 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_convert_snull(char **str, t_struct *flag)
{
    flag->snull = 1;
    *str = ft_strdup("(null)");
    return (6);
}

void    ft_convert_sutils(t_struct *flag, int len)
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
	if (flag->precision >= 0) //a revérifier pour superieur ou égale
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
