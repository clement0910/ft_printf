/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:54:53 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 22:27:47 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		x;
	unsigned char		*dstptr;
	unsigned const char	*srcptr;

	srcptr = (unsigned const char *)src;
	dstptr = (unsigned char *)dst;
	x = 0;
	while (x < n)
	{
		dstptr[x] = srcptr[x];
		if (srcptr[x] == (unsigned char)c)
		{
			x++;
			return (dst + x);
		}
		x++;
	}
	return (0);
}
