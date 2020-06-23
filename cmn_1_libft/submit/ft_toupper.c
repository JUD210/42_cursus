/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:12:55 by hmin              #+#    #+#             */
/*   Updated: 2020/04/18 03:07:14 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <ctype.h>
*/

/*
**	for (i = -100; i < 530; i++)
**	{
**		printf("%d | ", toupper(i));
**		printf("%d\n", ft_toupper(i));
**	}
**
**	i: -5  | toupper(i): 251
**	i: -4  | toupper(i): 252
**	i: -3  | toupper(i): 253
**	i: -2  | toupper(i): 254
**	i: -1  | toupper(i): -1
**	i:  0  | toupper(i): 0
**	i:  1  | toupper(i): 1
**	i:  2  | toupper(i): 2
**	i:  3  | toupper(i): 3
*/

/*
** int	ft_toupper(int c)
** {
** 	if (c < -1)
** 		c += 256;
** 	return ((c >= 'a' && c <= 'z') ? c - 32 : c);
** }
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}
