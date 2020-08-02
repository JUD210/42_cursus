/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_7_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:31:11 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_info *info, char *blank_width, char c)
{
	if (info->width < 2)
		info->width = 1;
	if (info->left_aligned == DISABLED && info->zero_fill == ENABLED)
		info->padding = '0';
	blank_width = fill_in_blank(info->width, info->padding);
	if (blank_width == NULL)
		return (NULL);
	if (info->left_aligned == ENABLED)
		blank_width[0] = c;
	else
		blank_width[info->width - 1] = c;
	return (blank_width);
}

int			print_percent(t_info *info)
{
	char	c;
	char	*res;
	t_blank	*blank;

	c = '%';
	blank = prepare_blank();
	if ((res = process_width(info, blank->width, c)) == NULL)
	{
		free_blank(blank);
		return (ERROR);
	}
	info->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_blank(blank);
	return (0);
}
