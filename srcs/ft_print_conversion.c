/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_conversion.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 10:15:14 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 14:50:22 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(t_struct *flag, va_list *arg)
{
	char *str;
	int len;

	str = va_arg(arg, char *);

}

int		findindex(char *tab, char element)
{
	int x;

	x = 0;
	while (tab[x])
	{
		if (tab[x] == element)
			return (x);
		x++;
	}
	return (-1);
}

void	ft_printconvert(const char *fmt, t_struct *flag, va_list arg, int *x)
{
	void (*tabFunction[7])(t_struct *,va_list *, int *) = {ft_convert_s, 
	ft_convert_d, ft_convert_c, ft_convert_p, ft_convert_u, ft_convert_x,
	ft_convert_xmaj};
	char tabIndex[8] = {'s', 'd', 'c', 'p', 'u', 'x', 'X', 0};
	int index;

	index = findindex(tabIndex, fmt[*x]);
	if (index == -1)
		return ;
	(*tabFunction[index]) (flag, arg, x);
}