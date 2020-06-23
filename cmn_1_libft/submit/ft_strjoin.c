/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:02:45 by hmin              #+#    #+#             */
/*   Updated: 2020/03/01 12:11:55 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_new;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s_new = (char *)malloc(size * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s_new[i] = s1[i];
	j = -1;
	while (s2[++j])
		s_new[i++] = s2[j];
	s_new[i] = '\0';
	return (s_new);
}
