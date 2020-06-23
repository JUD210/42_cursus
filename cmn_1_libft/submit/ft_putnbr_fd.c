/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:26:55 by hmin              #+#    #+#             */
/*   Updated: 2020/04/18 04:10:41 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}

/*
** yoolee's code
**
** void	ft_putnbr_fd(int n, int fd)
** {
** 	int		num;
**
** 	num = n;
** 	if (num == -2147483648)
** 	{
** 		ft_putstr_fd("-2147483648", fd);
** 		return ;
** 	}
** 	if (num < 0)
** 	{
** 		ft_putchar_fd('-', fd);
** 		num *= -1;
** 	}
** 	if (num > 10)
** 		ft_putnbr_fd(num / 10, fd);
** 	ft_putchar_fd((num % 10) + '0', fd);
** }
*/
