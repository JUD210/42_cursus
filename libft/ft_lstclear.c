/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:09:56 by hmin              #+#    #+#             */
/*   Updated: 2020/04/15 16:50:02 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	void	ft_lstdelone(t_list *list, void (*del)(void *))
** 	{
** 		if (!list || !del)
** 			return ;
** 		(*del)(list->content);
** 		free(list);
** 	}
*/

void	ft_lstclear(t_list **p_list, void (*del)(void *))
{
	t_list	**p_curr;
	t_list	*next_elem;

	if (!p_list || !(*p_list) || !del)
		return ;
	p_curr = p_list;
	while (*p_curr)
	{
		next_elem = (*p_curr)->next;
		ft_lstdelone(*p_curr, del);
		*p_curr = next_elem;
	}
}

/*
** void	ft_lstclear(t_list **p_list, void (*del)(void *))
** {
** 	t_list	*curr;
** 	t_list	*next_elem;
**
** 	if (!p_list || !(*p_list) || !del)
** 		return ;
** 	curr = *p_list;
** 	while (curr)
** 	{
** 		next_elem = (curr)->next;
** 		ft_lstdelone(curr, del);
** 		curr = next_elem;
** 	}
** 	*p_list = NULL;
** }
*/
