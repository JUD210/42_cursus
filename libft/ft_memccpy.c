/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:10:42 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 00:37:15 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	unsigned char	uc_c;
	size_t			idx;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	uc_c = (unsigned char)c;
	idx = -1;
	while (++idx < len)
	{
		if ((uc_dst[idx] = uc_src[idx]) == uc_c)
			return (dst + idx + 1);
	}
	return (NULL);
}
