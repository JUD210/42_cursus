/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:10:04 by hmin              #+#    #+#             */
/*   Updated: 2020/04/15 16:57:25 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	if (!(dst))
		return (0);
	if (!(src))
		return (0);
	idx = 0;
	if (dstsize != 0)
	{
		while (idx < dstsize - 1 && src[idx])
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (ft_strlen(src));
}

/*
** if (!(dst)) return (0);
** if (!(src)) return (0);
**
** for Protection!
*/
