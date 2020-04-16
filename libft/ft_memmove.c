/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:07:15 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 15:09:03 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	size_t			i;
	int				step;

	if (!dst && !src)
		return (NULL);
	step = 1;
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (dst > src)
	{
		step = -1;
		uc_dst = (unsigned char *)(dst + len - 1);
		uc_src = (unsigned char *)(src + len - 1);
	}
	i = -1;
	while (++i < len)
	{
		*uc_dst = *uc_src;
		uc_dst += step;
		uc_src += step;
	}
	return (dst);
}
