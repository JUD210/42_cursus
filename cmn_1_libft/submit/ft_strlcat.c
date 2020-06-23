/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:34:52 by hmin              #+#    #+#             */
/*   Updated: 2020/04/15 16:57:27 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	rtn_dst_len;
	size_t	start;
	size_t	idx;

	rtn_dst_len = 0;
	while (dst[rtn_dst_len] && rtn_dst_len < dstsize)
		rtn_dst_len++;
	start = ft_strlen(dst);
	if (dstsize != 0)
	{
		idx = 0;
		while (start + idx < dstsize - 1 && src[idx])
		{
			dst[start + idx] = src[idx];
			idx++;
		}
		dst[start + idx] = '\0';
	}
	return (rtn_dst_len + ft_strlen(src));
}

/*
**	size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
**	{
**		size_t	rtn_dst_len;
**		size_t	src_len;
**		size_t	idx;
**		size_t	start;
**
**		if (!(dst)) return (0);
**		if (!(src)) return (0);
**
**		idx = 0;
**		rtn_dst_len = 0;
**		while (dst[rtn_dst_len] && rtn_dst_len < dstsize)
**			rtn_dst_len++;
**		start = ft_strlen(dst);
**		src_len = ft_strlen(src);
**		while (start + idx < dstsize - 1 && src[idx])
**		{
**			dst[start + idx] = src[idx];
**			idx++;
**		}
**		dst[start + idx] = '\0';
**		return (rtn_dst_len + src_len);
**	}
**
**	ft_strlcat:    [OK] [OK] [OK] [OK] [FAILED] [OK] [OK] [OK] [OK] [OK]
**	[NO CRASH] [NO CRASH]
**	[fail]: your strlcat does not work with a size of 0
**	[no crash]: your strlcat does not segfault when null parameter is sent
**	[no crash]: your strlcat does not segfault when null parameter is sent
**
**
**	size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
**	{
**		size_t	rst_len;
**		size_t	src_len;
**		size_t	idx;
**		size_t	start;
**
**		if (!(dst)) return (0);
**		if (!(src)) return (0);
**
**		idx = 0;
**		start = 0;
**		while (dst[start])
**			start++;
**		rst_len = start;
**		src_len = ft_strlen(src);
**		if (dstsize != 0)
**		{
**			while (idx < dstsize - 1 && dst[start + idx] && src[idx])
**			{
**				dst[start + idx] = src[idx];
**				idx ++;
**			}
**			dst[start + idx] = '\0';
**		}
**		return (rst_len + src_len);
**	}
**
**	ft_strlcat:    [OK] [FAILED] [FAILED] [FAILED] [OK] [OK] [FAILED] [FAILED]
**	[OK] [OK] [NO CRASH] [NO CRASH]
**	[fail]: your strlcat does not work with basic input
**	[fail]: your strlcat does not work with basic input
**	[fail]: your strlcat does not work with over length size
**	[fail]: your strcat does not work with empty string as second parameter
**	[fail]: your strlcat does not set a \0 to the end
**	[no crash]: your strlcat does not segfault when null parameter is sent
**	[no crash]: your strlcat does not segfault when null parameter is sent
**
**
**	size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
**	{
**		size_t	rst_len;
**		size_t	src_len;
**		size_t	idx;
**		size_t	start;
**
**		if (!(dst)) return (0);
**		if (!(src)) return (0);
**
**		rst_len = ft_strlen(dst);
**		src_len = ft_strlen(src);
**		idx = 0;
**		start = rst_len + 1;
**		if (dstsize != 0)
**		{
**			while (idx < dstsize - 1 && dst[start + idx] && src[idx])
**			{
**				dst[start + idx] = src[idx];
**				idx ++;
**			}
**			dst[start + idx] = '\0';
**		}
**		return (rst_len + src_len);
**	}
**
**	ft_strlcat:    [OK] [FAILED] [FAILED] [FAILED] [OK] [OK] [FAILED] [FAILED]
**	[CRASH] [OK] [NO CRASH] [NO CRASH]
**	[fail]: your strlcat does not work with basic input
**	[fail]: your strlcat does not work with basic input
**	[fail]: your strlcat does not work with over length size
**	[fail]: your strcat does not work with empty string as second parameter
**	[fail]: your strlcat does not set a \0 to the end
**	[crash]: your strlcat crash because it read too many bytes or attempt to
**	write on buff !
**	[no crash]: your strlcat does not segfault when null parameter is sent
**	[no crash]: your strlcat does not segfault when null parameter is sent
*/
