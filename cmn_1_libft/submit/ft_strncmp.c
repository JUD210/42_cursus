/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:27:23 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 00:06:35 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
** return (ft_memcmp(s1, s2, len));
** [fail]: your strncmp doesn't stop at \0
*/

/*
** 	int ft_strncmp_f(const char *s1, const char *s2, size_t len)
** 	{
** 		size_t i;
**
** 		i = 0;
** 		while (i < len && s1[i] != '\0' && s2[i] != '\0')
** 		{
** 			if (s1[i] != s2[i])
** 				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
** 			i++;
** 		}
**
** 		return (0);
** 	}
** 	// [fail]: your strncmp does not work with zero length string
** 	// [fail]: your strncmp does not work with zero length string
** 	// [fail]: your strncmp does not cast in unsigned char the diff
**
** 	int ft_strncmp_s2(const char *s1, const char *s2, size_t len)
** 	{
** 		size_t i;
**
** 		i = 0;
** 		while (i < len && s1[i] != '\0' && s2[i] != '\0')
** 		{
** 			if (s1[i] != s2[i])
** 				break;
** 			i++;
** 		}
** 		if (i != len)
** 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
** 		else
** 			return (0);
** 	}
**
** 	int ft_strncmp_s3(const char *s1, const char *s2, size_t n)
** 	{
** 		while (n > 0 && *s1 != '\0' && *s2 != '\0')
** 		{
** 			if (*s1 != *s2)
** 				break;
** 			s1++;
** 			s2++;
** 			n--;
** 		}
** 		if (n == 0)
** 			return (0);
** 		return (*(unsigned char *)s1 - *(unsigned char *)s2);
** 	}
*/
