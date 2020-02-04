/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:44:09 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 15:09:23 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int x;
	int resultat;
	int neg;

	resultat = 0;
	x = 0;
	neg = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			neg = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		resultat = resultat * 10 + (str[x] - 48);
		x++;
	}
	return (resultat * neg);
}
