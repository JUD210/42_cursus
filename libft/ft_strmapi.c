/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:13:57 by hmin              #+#    #+#             */
/*   Updated: 2020/03/01 23:56:04 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*str_new;
	int		str_new_len;
	int		i;

	if (!(str))
		return (NULL);
	str_new_len = ft_strlen(str);
	str_new = ft_calloc(str_new_len + 1, sizeof(char));
	i = -1;
	while (str[++i])
		str_new[i] = (*f)(i, str[i]);
	str_new[i] = '\0';
	return (str_new);
}
