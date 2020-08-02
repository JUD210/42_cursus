/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:34:37 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:08:50 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int atoi;
	int sign;

	sign = 1;
	while (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -sign : sign;
		str++;
	}
	atoi = 0;
	if (!is_in_set(*str, DIGIT))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + (*str - '0');
		str++;
	}
	return (atoi * sign);
}
