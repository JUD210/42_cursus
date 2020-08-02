/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:30:29 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pre_print_char(va_list ap, t_info *info)
{
	char	c;

	c = (char)va_arg(ap, int);
	return (print_char(info, c));
}

int	pre_print_string(va_list ap, t_info *info)
{
	char	*res;

	res = va_arg(ap, char *);
	return (print_string(info, res));
}

int	pre_print_int(va_list ap, t_info *info)
{
	char	*res;

	res = ft_itoa((int)va_arg(ap, int));
	if (res == NULL)
		return (ERROR);
	else
		return (print_int(info, res));
}

int	pre_print_unsigned_int(va_list ap, t_info *info)
{
	char	*res;

	res = ft_uitoa((unsigned int)va_arg(ap, int));
	if (res == NULL)
		return (ERROR);
	else
		return (print_unsigned_int(info, res));
}

int	pre_print_hexa(va_list ap, t_info *info, char *base)
{
	char	*res;

	res = ft_itoa_base((int)va_arg(ap, int), base);
	if (res == NULL)
		return (ERROR);
	else
		return (print_hexa(info, res));
}
