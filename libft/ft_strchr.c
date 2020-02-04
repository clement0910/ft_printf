/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:35:22 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 11:41:06 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return ((char *)str + x);
		x++;
	}
	if (c == '\0')
		return ((char *)str + x);
	return (0);
}
