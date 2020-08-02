/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:30:45 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_info *info, char *blank_width)
{
	info->width--;
	if (info->width < 1)
		return ("");
	blank_width = fill_in_blank(info->width, info->padding);
	if (blank_width == NULL)
		return (NULL);
	return (blank_width);
}

int			print_char(t_info *info, char c)
{
	char	*res;
	t_blank	*blank;

	if (info->prcs > 0)
		return (WARNING);
	blank = prepare_blank();
	if ((res = process_width(info, blank->width)) == NULL)
	{
		free_blank(blank);
		return (ERROR);
	}
	if (info->left_aligned == ENABLED)
		info->nbyte += ft_putchar(c) + ft_putstr(res);
	else
		info->nbyte += ft_putstr(res) + ft_putchar(c);
	free_blank(blank);
	return (0);
}
