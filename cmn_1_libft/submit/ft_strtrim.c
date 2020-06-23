/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:12:15 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 21:11:29 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char		*ft_strtrim(const char *str, const char *set)
{
	char	*str_new;
	int		start;
	int		end;
	int		str_new_l;

	start = -1;
	while (str[++start])
		if (!is_in_set(set, str[start]))
			break ;
	end = ft_strlen(str);
	while (str[--end])
		if (!is_in_set(set, str[end]))
			break ;
	if (end < start)
		return (ft_strdup(""));
	str_new_l = end - start + 1;
	if (!(str_new = (char *)malloc((str_new_l + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(str_new, &str[start], str_new_l);
	str_new[str_new_l] = '\0';
	return (str_new);
}
