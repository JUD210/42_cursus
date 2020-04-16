/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:14:05 by hmin              #+#    #+#             */
/*   Updated: 2020/03/02 22:30:02 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *list, void (*del)(void *))
{
	if (!list || !del)
		return ;
	(*del)(list->content);
	free(list);
}

/*
** Do NOT state below!
** (*del)(list->next);
**
** ft_lstdelone
**
** Takes as a parameter an element and frees the
** memory of the element’s content using the function
** ’del’ given as a parameter and free the element.
** The memory of ’next’ must not be freed.
**
** The purpose of ft_lstdelone is deleting and freeing an "ELEMENT"!
** i.e. "LIST"!
**
** And, ... del function's purpose is free!
** if you use del(list->next), del will free next list accidently!
**
** Your purpose to erase 'list->next' either can be performed by just
** list->next = NULL;
**
** But, I guess it's not necessary because the problem didn't require it,
** and MAYBE! free(list) will do that automatically.
** or MAYBE! they doesn't care about 1byte for a useless pointer variable.
**
** And I'm curious.
** In many courses and books, deleting a 'current' list
** requires connecting 'front' and 'back' list by using tmp pointer.
** Why ft_lstdelone just cut it off forcefully?
** Then how to deal with array list which is lost chain by this func?
**
** ... @Todo later
*/
