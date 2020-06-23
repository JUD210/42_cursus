/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:35:29 by hmin              #+#    #+#             */
/*   Updated: 2020/04/18 01:30:37 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #include <stdlib.h>
*/

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*bytes;
	int		len;

	len = number * size;
	if (!(bytes = malloc(len)))
		return (NULL);
	ft_memset(bytes, 0, len);
	return (bytes);
}
