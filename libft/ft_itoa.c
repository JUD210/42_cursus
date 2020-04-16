/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:10:30 by hmin              #+#    #+#             */
/*   Updated: 2020/03/01 23:13:01 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*str_rst;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n >= 0) ? 1 : -1;
	n = (n >= 0) ? n : -n;
	if (!(str = (char *)malloc(12 * sizeof(char))))
		return (NULL);
	str[11] = '\0';
	i = 10;
	while (n != 0 || i == 10)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (sign == -1)
		str[i--] = '-';
	i++;
	str_rst = ft_substr(str, i, 12 - i);
	free(str);
	return (str_rst);
}
