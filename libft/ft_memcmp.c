/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 17:06:56 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 21:21:23 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		x;
	unsigned const char	*s1ptr;
	unsigned const char	*s2ptr;

	x = 0;
	s1ptr = s1;
	s2ptr = s2;
	if (n == 0)
		return (0);
	while (s1ptr[x] == s2ptr[x] && x < (n - 1))
		x++;
	return ((unsigned char)s1ptr[x] - (unsigned char)s2ptr[x]);
}
