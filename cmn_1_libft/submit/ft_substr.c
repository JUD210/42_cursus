/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:53:02 by hmin              #+#    #+#             */
/*   Updated: 2020/04/18 02:50:14 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Imported yoolee's code
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*
** FXXKIN malfunctioning my code
**
** char	*ft_substr(const char *str, unsigned int start, size_t len)
** {
** 	char	*sub_str;
** 	size_t	start_;
** 	size_t	i;
**
** 	if (!(sub_str = (char *)malloc((len + 1) * sizeof(char))))
** 		return (NULL);
** 	if (start >= (unsigned int)ft_strlen(str))
** 		return (sub_str);
** 		// return (NULL);
** 	start_ = (size_t)start;
** 	i = 0;
** 	while (str[start_ + i] && i < len)
** 	{
** 		sub_str[i] = str[start_ + i];
** 		i++;
** 	}
** 	sub_str[i] = '\0';
** 	return (sub_str);
** }
*/

/*
** 	if (start >= ft_strlen(str))
** 		return (NULL);
**
** If this is not used, moulenette gives fail (ex: ft_substr("test", 10, 1))
** But If this is used, ft_itoa suddenly fails with printing nothing
**
** WTF IS THAT?! DAMN IT
*/

/*
** #include <stdio.h>
**
** int	main(void)
** {
** 	int i;
** 	int j;
**
** 	for (i=0; i<11; i++)
** 	{
** 		for (j=0; j<11; j++)
** 		{
** 			printf("[%d][%d]|%s|\n", i, j, ft_substr("asdfqwer", i, j));
** 			printf("[%d][%d]|%s|\n", i, j, ft_substr2("asdfqwer", i, j));
** 		}
** 	}
**
** 	return (0);
** }
*/
