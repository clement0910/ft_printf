/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 12:27:17 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 11:21:20 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstptr;
	unsigned char		*srcptr;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	if (srcptr < dstptr)
	{
		len++;
		while (--len)
			dstptr[len - 1] = srcptr[len - 1];
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
