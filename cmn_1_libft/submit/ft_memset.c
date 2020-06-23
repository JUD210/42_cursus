/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:43:49 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 15:07:56 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

void	*ft_memset(void *dst, int src, size_t len)
{
	unsigned char	*uc_dst;
	size_t			idx;

	uc_dst = (unsigned char *)dst;
	idx = -1;
	while (++idx < len)
		uc_dst[idx] = src;
	return (dst);
}

/*
************************************************************
**
** Copy N bytes of SRC to dst.
**
** The reason why the 'void' pointer was used is
** because dst is 'bytes' (not 'str' == 'chars').
**
** so, any type of arguments' starting point can be pointed by dst
**
** if    *(dst)     == &dst[0] == 0x10
** then  *(dst + 1) == &dst[1] == 0x11
**       *(dst + 2) == &dst[2] == 0x12
**
************************************************************
**
** If an argument for dst is not a string, src should be input 0!
** I'll show you what happens if I input a value which is not 0.
**
** int n = 5;
** // (== 101)
** // (== 00000000 00000000 00000000 00000101)
**        0x13     0x12     0x11     0x10
**
**		  0x10 00000101
**		  0x11 00000000
**		  0x12 00000000
**		  0x13 00000000
**
**
** ft_memset(&n, 2, 3);
**
** printf("%d", n);
** // 131586
** // (== 100000001000000010)
** // (== 10 00000010 00000010)
** // (== 00000000 00000010 00000010 00000010)
**        0x13     0x12     0x11     0x10
**
**		  0x10 00000010
**		  0x11 00000010
**		  0x12 00000010
**		  0x13 00000000
**
**
** ft_memset(&n, 2, sizeof(int));
**
** printf("%d", n);
** // 33686018
** // (== 100000001000000010)
** // (== 10 00000010 00000010)
** // (== 00000000 00000010 00000010 00000010)
**        0x13     0x12     0x11     0x10
**
**		  0x10 00000010
**		  0x11 00000010
**		  0x12 00000010
**		  0x13 00000010
**
**
** ft_memset(&n, 2, 100000);
**
** printf("%d", n);
** // 33686018
** // (== 100000001000000010)
** // (== 10 00000010 00000010)
** // (== 00000000 00000010 00000010 00000010)
**        0x13     0x12     0x11     0x10
**
**		  0x10 00000010
**		  0x11 00000010
**		  0x12 00000010
**		  0x13 00000010
**		  --------------------
**        Start Accessing Random Address!! (maybe ?)
**		  --------------------
**		  0x14 00000010
**		  0x15 00000010
**		  ...
**		  ... (skip)
**
**	// Actually, the result of printf("%d", n); can't be printed
**	// because of below error.
**  //
**	// Segmentation fault (core dumped)
************************************************************
*/
