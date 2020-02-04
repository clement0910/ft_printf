/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 23:07:33 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 11:15:07 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	int		x;
	int		y;

	y = ft_strlen(str) - 1;
	x = 0;
	while ((unsigned int)x < (ft_strlen(str) / 2))
	{
		temp = str[y];
		str[y] = str[x];
		str[x] = temp;
		y--;
		x++;
	}
	return (str);
}
