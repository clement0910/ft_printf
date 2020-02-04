/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 18:20:51 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 18:54:04 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		x;
	unsigned char		*dstptr;
	unsigned const char	*srcptr;

	srcptr = src;
	dstptr = dst;
	x = 0;
	if (!src && !dst)
		return (0);
	while (x < n)
	{
		dstptr[x] = srcptr[x];
		x++;
	}
	return (dst);
}
