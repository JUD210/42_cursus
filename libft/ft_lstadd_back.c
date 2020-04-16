/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:57:02 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 00:37:15 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **p_head, t_list *new)
{
	if (!p_head)
		return ;
	if (!(*p_head))
		*p_head = new;
	else
		ft_lstlast(*p_head)->next = new;
}
