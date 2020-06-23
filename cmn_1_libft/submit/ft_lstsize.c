/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:11:13 by hmin              #+#    #+#             */
/*   Updated: 2020/03/02 14:58:06 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *head)
{
	int		lst_size;
	t_list	*curr;

	lst_size = 0;
	curr = head;
	while (curr != NULL)
	{
		lst_size++;
		curr = curr->next;
	}
	return (lst_size);
}
