/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 10:25:36 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 11:44:17 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*toreturn;
	int		alloc;

	alloc = size * count;
	if (!(toreturn = malloc(alloc)))
		return (0);
	ft_bzero(toreturn, alloc);
	return ((void*)toreturn);
}
