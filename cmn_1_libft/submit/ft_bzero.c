/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:31:54 by hmin              #+#    #+#             */
/*   Updated: 2020/02/27 23:36:43 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	#include <strings.h>
*/

#include "libft.h"

/*
** write zeroes to a byte string
**
** The bzero() function writes len zero bytes to the string.
** if len is zero, bzero() does	nothing.
*/

void	ft_bzero(void *dst, size_t len)
{
	ft_memset(dst, 0, len);
}
