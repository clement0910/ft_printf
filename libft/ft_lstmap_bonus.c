/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 15:30:53 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 20:16:25 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if (lst && f)
	{
		if (!(current = ft_lstnew((*f)(lst->content))))
			return (NULL);
		first = current;
		lst = lst->next;
		while (lst)
		{
			if (!(current->next = ft_lstnew((*f)(lst->content))))
			{
				ft_lstclear(&first, (*del));
				return (NULL);
			}
			current = current->next;
			lst = lst->next;
		}
		return (first);
	}
	return (NULL);
}
