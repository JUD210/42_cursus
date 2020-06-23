/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:10:39 by hmin              #+#    #+#             */
/*   Updated: 2020/03/03 01:07:30 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*curr;
	t_list	*new_curr;

	if (!list)
		return (NULL);
	if (!(new_list = ft_lstnew((*f)(list->content))))
		return (NULL);
	curr = list->next;
	new_curr = new_list;
	while (curr != NULL)
	{
		if (!(new_curr->next = ft_lstnew((*f)(curr->content))))
			ft_lstclear(&new_list, del);
		new_curr = new_curr->next;
		curr = curr->next;
	}
	return (new_list);
}

/*
** more short and clear solution
**
** t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
** {
**     t_list  *new;
**     t_list  *tmp;
**     new = NULL;
**     while (lst && f && del)
**     {
**         if (!(tmp = ft_lstnew(f(lst->content))))
**         {
**             ft_lstclear(&new, del);
**             return (NULL);
**         }
**         ft_lstadd_back(&new, tmp);
**         lst = lst->next;
**     }
**     return (new);
** }
*/
