/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_aux.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 13:11:02 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 13:18:42 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_multipleswrite(int x, char c)
{
	while (x > 0)
	{
		write(1, &c, 1);
		x--;
	}
}

int	ft_intlen(int x)
{
	int i;

	i = 0;
	if (x < 0)
		x = x * -1;
	while (x > 0)
	{
		x = x / 10;
		i++;	
	}
	return (i);
}

int     ft_howmanymalloc(unsigned int nbr, char *base)
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

char    *ft_utoa_base(unsigned int nbr, char *base)
{
    int x;
    int m;
    char *str;
    int lenbase;

    x = 0;
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

int		ft_uintlen(unsigned int t) //Peux remplacer par how_many_malloc ?
{
	int x;

	x = 0;
	while (t > 0)
	{
		t = t / 10;
		x++;	
	}
	return (x);
}
