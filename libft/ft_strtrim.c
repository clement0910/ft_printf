/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:44:58 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 21:21:55 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		x;
	int		i;
	int		t;

	t = 0;
	x = 0;
	if (!s1 || !set)
		return (0);
	i = (ft_strlen(s1) == 0) ? 1 : ft_strlen(s1);
	while (ft_chrcmp((char *)set, s1[x]) == 0)
		x++;
	while ((ft_chrcmp((char *)set, s1[i - 1]) == 0))
	{
		i--;
		if (i == 0)
			return (str = ft_calloc(1, sizeof(char)));
	}
	if (!(str = malloc(((i - x) + 1) * sizeof(char))))
		return (0);
	while (x < i)
		str[t++] = s1[x++];
	str[t] = '\0';
	return (str);
}
