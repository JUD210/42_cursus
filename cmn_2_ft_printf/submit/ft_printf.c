/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:29:23 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_matcher(char *fmt, va_list ap, t_info *info)
{
	if (*fmt == 'c')
		return (pre_print_char(ap, info));
	else if (*fmt == 's')
		return (pre_print_string(ap, info));
	else if (*fmt == 'd' || *fmt == 'i')
		return (pre_print_int(ap, info));
	else if (*fmt == 'u')
		return (pre_print_unsigned_int(ap, info));
	else if (*fmt == 'x')
		return (pre_print_hexa(ap, info, HEX_LOWER));
	else if (*fmt == 'X')
		return (pre_print_hexa(ap, info, HEX_UPPER));
	else if (*fmt == 'p')
		return (print_pointer(ap, info));
	else if (*fmt == '%')
		return (print_percent(info));
	else
		return (ERROR);
}

static void	prepare_new_info(t_info *info)
{
	info->left_aligned = DISABLED;
	info->width = DISABLED;
	info->prcs = DISABLED;
	info->zero_fill = DISABLED;
	info->sign = '\0';
	info->padding = ' ';
}

static int	process_format(char *fmt, va_list ap)
{
	t_info	info;

	info.nbyte = 0;
	if (fmt == 0)
		return (ERROR);
	while (*fmt)
	{
		while (*fmt != '%' && *fmt)
		{
			info.nbyte += ft_putchar(*fmt);
			fmt++;
		}
		if (*fmt == '%')
		{
			fmt++;
			prepare_new_info(&info);
			if (format_analyzer(&fmt, ap, &info) == ERROR)
				return (ERROR);
			if (print_matcher(fmt, ap, &info) == ERROR)
				return (ERROR);
			fmt++;
		}
	}
	return (info.nbyte);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nbyte;

	va_start(ap, format);
	if ((nbyte = process_format((char *)format, ap)) == ERROR)
		return (ERROR);
	va_end(ap);
	return (nbyte);
}
