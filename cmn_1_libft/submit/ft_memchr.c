/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:26:45 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 00:37:15 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

/*
** return ((void *)b + idx);
** return ((unsigned char *)b + idx);
** both are correct!
*/

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*uc_b;
	unsigned char	uc_c;
	size_t			idx;

	uc_b = (unsigned char *)b;
	uc_c = (unsigned char)c;
	idx = -1;
	while (++idx < len)
	{
		if (uc_b[idx] == uc_c)
			return ((void *)b + idx);
	}
	return (NULL);
}
