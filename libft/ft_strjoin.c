/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:12:40 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 16:54:08 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		i;
	char	*str;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = (char *)malloc(ft_strlen((char *)s1) +
	ft_strlen((char *)s2) + 1)))
		return (0);
	while (s1[x] != '\0')
		str[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[x++] = s2[i++];
	str[x] = '\0';
	return (str);
}
