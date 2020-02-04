/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:32:05 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 22:48:44 by clement     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	x;
	unsigned char	*ptr;

	ptr = b;
	x = 0;
	while (x < len)
	{
		ptr[x] = (unsigned char)c;
		x++;
	}
	return ((void *)b);
}
