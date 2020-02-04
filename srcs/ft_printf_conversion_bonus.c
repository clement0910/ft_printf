/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion_bonus.c                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 17:04:17 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 17:05:04 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

void	ft_convert_n(t_struct *flag, va_list arg)
{
	int	*r;

	r = va_arg(arg, int*);
	*r = flag->write;
}