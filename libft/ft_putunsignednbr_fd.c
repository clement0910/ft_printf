/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putunsignednbr_fd.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 11:38:43 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 18:22:25 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignednbr_fd(unsigned int x, int fd)
{
	if (x < 10)
		ft_putchar_fd(x + 48, fd);
	else
	{
		ft_putunsignednbr_fd(x / 10, fd);
		ft_putunsignednbr_fd(x % 10, fd);
	}
}
