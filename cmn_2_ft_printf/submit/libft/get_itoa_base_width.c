/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_base_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:38:12 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:08:50 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_itoa_base_width(long n, long size)
{
	int			i;
	long long	long_n;

	i = n < 1 ? 1 : 0;
	n = n < 0 ? -n : n;
	long_n = n < 0 ? -(long long)n : (long long)n;
	while (long_n != 0)
	{
		long_n = long_n / size;
		i++;
	}
	return (i);
}

/*
** get return value except '-' sign to meet 'prcs' requiremnet
*/
