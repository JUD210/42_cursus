/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:01:30 by hmin              #+#    #+#             */
/*   Updated: 2020/03/02 19:31:09 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *curr, void (*f)(void *))
{
	if (!curr || !f)
		return ;
	while (curr != NULL)
	{
		(*f)(curr->content);
		curr = curr->next;
	}
}
