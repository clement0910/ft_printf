/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:36:17 by csapt             #+#    #+#             */
/*   Updated: 2020/05/22 20:36:18 by csapt            ###   ########lyon.fr   */
/*                                                                            */
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
