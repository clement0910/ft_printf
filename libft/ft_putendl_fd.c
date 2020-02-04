/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 17:15:06 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 17:17:12 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int x;

	x = 0;
	if (s == NULL)
		return ;
	while (s[x] != '\0')
		ft_putchar_fd(s[x++], fd);
	ft_putchar_fd('\n', fd);
}
