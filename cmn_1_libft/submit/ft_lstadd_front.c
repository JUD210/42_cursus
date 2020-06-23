/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 01:00:08 by hmin              #+#    #+#             */
/*   Updated: 2020/03/02 20:16:49 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **p_head, t_list *new)
{
	if (!p_head || !new)
		return ;
	if (!(*p_head))
		*p_head = new;
	else
	{
		new->next = *p_head;
		*p_head = new;
	}
}

/*
***************************************************************
** 	struct node* push(struct node **head, int data)
** 	{
** 		struct node* newnode = malloc(sizeof(struct node));
** 		newnode->data = data;
** 		newnode->next = *head;
** 		return newnode;
** 	}
**
** 	push(&head,1);
***************************************************************
** 	struct node* push(struct node *head, int data)
** 	{
** 		struct node* newnode = malloc(sizeof(struct node));
** 		newnode->data = data;
** 		newnode->next = head;
** 		return newnode;
** 	}
**
** 	push(head,1);
***************************************************************
*/
