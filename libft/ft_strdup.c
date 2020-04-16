/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:51:51 by hmin              #+#    #+#             */
/*   Updated: 2020/03/01 18:03:11 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <string.h>
*/

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup_str;
	int		str_len;
	int		i;

	str_len = ft_strlen(str);
	dup_str = (char *)malloc((str_len + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
