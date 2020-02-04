/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 15:43:27 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 15:59:22 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	x;

	x = 0;
	if (!s)
		return (0);
	if (!(str = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	while (s[x] != '\0')
	{
		str[x] = (*f)(x, s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
