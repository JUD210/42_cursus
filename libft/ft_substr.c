/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:53:02 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 00:06:46 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	start_;
	size_t	i;

	if (!(sub_str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	start_ = (size_t)start;
	i = 0;
	while (str[start_ + i] && i < len)
	{
		sub_str[i] = str[start_ + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
