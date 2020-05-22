/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:35:29 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:35:30 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printb_hexa(int *x, t_struct *flag)
{
	(*x)++;
	flag->b_hexa = 1;
	return (1);
}

int		ft_printb_plus(int *x, t_struct *flag)
{
	(*x)++;
	flag->b_plus = 1;
	return (1);
}

int		ft_printb_space(int *x, t_struct *flag)
{
	(*x)++;
	flag->b_space = 1;
	return (1);
}

int		ft_printh_specs(int *x, t_struct *flag, char *fmt)
{
	(*x)++;
	if (fmt[*x] == 'h')
	{
		flag->b_h = 2;
		(*x)++;
	}
	else
		flag->b_h = 1;
	return (1);
}

int		ft_printl_specs(int *x, t_struct *flag, char *fmt)
{
	(*x)++;
	if (fmt[*x] == 'l')
	{
		flag->b_l = 2;
		(*x)++;
	}
	else
		flag->b_l = 1;
	return (1);
}
