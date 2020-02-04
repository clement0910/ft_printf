/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:36:53 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 21:16:59 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int				x;
	unsigned char				*sptr;

	x = 0;
	sptr = (unsigned char *)s;
	while (x < n)
	{
		if (sptr[x] == (unsigned char)c)
			return ((char *)s + x);
		x++;
	}
	return (0);
}
