/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:13:46 by hmin              #+#    #+#             */
/*   Updated: 2020/04/15 16:57:27 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

/*
** function locates the first occurrence of c (converted to a char)
** in the string pointed to by s.
**
** The terminating null character is considered part of the string;
** therefore if c is `\0', the functions lo- cate the terminating `\0'.
*/

/*
** return(ft_memchr(s, c, sizeof(s)));
** [fail]: your strchr does not work with the char before \0
** [fail]: your strchr find chars after \0
** [fail]: your strchr does not work with \0
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
