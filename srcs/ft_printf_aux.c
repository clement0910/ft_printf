/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_aux.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 13:11:02 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 18:05:39 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_multipleswrite(int x, char c, t_struct *flag)
{
	while (x > 0)
	{
		write(1, &c, 1);
        flag->write++;
		x--;
	}
}

int	ft_intlen(int x)
{
	int i;

	i = 0;
	if (x < 0)
		x = x * -1;
    if (x == 0)
        return (1);
	while (x > 0)
	{
		x = x / 10;
		i++;	
	}
	return (i);
}

int     ft_howmanymalloc(unsigned long long int nbr, char *base)
{
    int lenbase;
    int x;

    x = 0;
    lenbase = ft_strlen(base);
    while (nbr > 0)
    {
        nbr = nbr / lenbase;
        x++;
    }
    return (x);
}

char    *ft_ulltoa_base(unsigned long long int nbr, char *base)
{
    int x;
    int m;
    char *str;
    int lenbase;

    x = 0;
	if (nbr == 0)
		return (ft_utoa_zero());
    lenbase = ft_strlen(base);
    m = ft_howmanymalloc(nbr, base);
    str = malloc((m + 1) * sizeof(char));
    while (nbr > 0)
    {
        str[x] = base[nbr % lenbase];
        nbr = nbr / lenbase;
        x++;
    }
    str[x] = '\0';
    ft_strrev(str);
    return (str);
}

char    *ft_utoa_base(unsigned int nbr, char *base)
{
    int x;
    int m;
    char *str;
    int lenbase;

    x = 0;
	if (nbr == 0)
		return (ft_utoa_zero());
    lenbase = ft_strlen(base);
    m = ft_howmanymalloc(nbr, base);
    str = malloc((m + 1) * sizeof(char));
    while (nbr > 0)
    {
        str[x] = base[nbr % lenbase];
        nbr = nbr / lenbase;
        x++;
    }
    str[x] = '\0';
    ft_strrev(str);
    return (str);
}

char 	*ft_utoa_zero(void)
{
	char *str;

	str = malloc(2 * sizeof(char));
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int		ft_uintlen(unsigned int t) //Peux remplacer par how_many_malloc ?
{
	int x;

	x = 0;
    if (t == 0)
        return (1);
	while (t > 0)
	{
		t = t / 10;
		x++;	
	}
	return (x);
}

void       ft_initstruct(t_struct *flag)
{
    flag->precision = -1;
    flag->widthnbr = -1;
    flag->space = 0;
    flag->nspace = 0;
    flag->write = 0;
    flag->snull = 0;
    flag->zero = 0;
}

void       ft_refreshstruct(t_struct *flag)
{
    flag->precision = -1;
    flag->widthnbr = -1;
    flag->space = 0;
    flag->nspace = 0;
    flag->snull = 0;
    flag->zero = 0;
}

void    ft_putnbrunsigned(unsigned int x)
{
        if (x < 10)
                ft_putchar_fd(x + 48, 1);
        else 
        {
                ft_putnbrunsigned(x / 10);
                ft_putnbrunsigned(x % 10);
        }
}
