/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:43:36 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 14:36:14 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*tmp_b1;
	unsigned char	*tmp_b2;
	size_t			i;

	tmp_b1 = (unsigned char *)b1;
	tmp_b2 = (unsigned char *)b2;
	i = -1;
	while (++i < len)
	{
		if (tmp_b1[i] != tmp_b2[i])
			return (tmp_b1[i] - tmp_b2[i]);
	}
	return (0);
}
