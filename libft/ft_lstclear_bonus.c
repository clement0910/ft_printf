/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 18:17:22 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 14:21:03 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (!*lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		(*del)(temp->content);
		*lst = temp->next;
		free(temp);
		temp = *lst;
	}
	lst = NULL;
}
