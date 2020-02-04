/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 17:59:01 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 12:10:42 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int x;

	x = ft_strlen(s);
	while (x > 0)
	{
		if (s[x] == c)
			return ((char *)s + x);
		x--;
	}
	if (s[x] == c)
		return ((char *)s);
	return (0);
}
