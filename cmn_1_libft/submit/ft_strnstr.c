/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:47:05 by hmin              #+#    #+#             */
/*   Updated: 2020/04/18 01:16:52 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && big[i + j])
	{
		j = 0;
		while (big[i + j] && little[j])
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (i + j > len)
			break ;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
** #include <stdio.h>
** #include <string.h>
**
** int	main(void)
** {
** 	int i;
** 	for (i=0; i<10; i++)
** 	{
** 		printf("[%d]|%s|\n", i, ft_strnstr("asdf1234", "a", i));
** 		printf("[%d]|%s|\n", i, strnstr("asdf1234", "a", i));
** 	}
** 	return (0);
** }
*/
