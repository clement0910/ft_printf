/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 19:05:25 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 14:35:59 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*s1_tmp;
	unsigned char		*s2_tmp;

	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_tmp[i] == s2_tmp[i] && s1_tmp[i] != 0 && n - 1 > i)
		i++;
	return ((int)(s1_tmp[i] - s2_tmp[i]));
}
