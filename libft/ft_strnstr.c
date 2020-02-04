/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 21:10:30 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 14:20:50 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t x;
	size_t i;

	x = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[x] != '\0' && x < len)
	{
		if (s1[x] == s2[0])
		{
			i = 0;
			while (s1[x + i] == s2[i] && (x + i) < len
				&& s1[x + i] != '\0' && s2[i] != '\0')
			{
				i++;
				if (s2[i] == '\0')
					return ((char *)s1 + x);
			}
		}
		x++;
	}
	return (0);
}
