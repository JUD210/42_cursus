/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:00:03 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 14:36:34 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

/*
** 	if (dst == NULL && src == NULL)
** 		return (NULL);
**
**	[crash]: your memcpy does not behave well with NULL as both params with size
*/

/*
** char str[] = "0123456789"
**
** memcpy((void *)&str[1], (void *)&str[3], 5);
** src 0 1 2 3-4-5-6-7 8 9 N
** dst 0 1-2-3-4-5 6 7 8 9 N
** rst 0 3 4 5 6 7 6 7 8 9 N
**
** memcpy((void *)&str[5], (void *)&str[3], 5);
** src 0 1 2 3-4-5-6-7 8 9 N
** dst 0 1 2 3 4 5-6-7-8-9 N
** rst 0 1 2 3 4 3 4 3 4 3 N
**
** memmove((void *)&str[5], (void *)&str[3], 5);
** src 0 1 2 3-4-5-6-7 8 9 N
** dst 0 1 2 3 4 5-6-7-8-9 N
** rst 0 1 2 3 4 3 4 5 6 7 N
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	size_t			idx;

	if (!dst && !src)
		return (NULL);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	idx = -1;
	while (++idx < len)
		uc_dst[idx] = uc_src[idx];
	return (dst);
}
