/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:33:42 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:33:43 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putlongnbr(long long x, int fd)
{
	if (x < 10)
		ft_putchar_fd(x + 48, fd);
	else
	{
		ft_putlongnbr(x / 10, fd);
		ft_putlongnbr(x % 10, fd);
	}
}

void		ft_putunsignedlongnbr(unsigned long long x, int fd)
{
	if (x < 10)
		ft_putchar_fd(x + 48, fd);
	else
	{
		ft_putunsignedlongnbr(x / 10, fd);
		ft_putunsignedlongnbr(x % 10, fd);
	}
}
