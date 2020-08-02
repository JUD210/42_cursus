/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_5_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:31:03 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_info *info, char *blank_prcs, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (info->prcs >= 0)
		info->zero_fill = DISABLED;
	if (s[0] == '0' && info->prcs == 0)
		return (s = "");
	if (info->prcs <= s_len)
		return (s);
	blank_prcs = fill_in_blank(info->prcs, '0');
	if (blank_prcs == NULL)
		return (NULL);
	ft_strcpy(&blank_prcs[info->prcs - s_len], s);
	return (blank_prcs);
}

static char	*process_width(t_info *info, char *blank_width, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (info->width <= s_len)
		return (s);
	if (info->zero_fill == ENABLED && info->prcs == DISABLED)
		info->padding = '0';
	blank_width = fill_in_blank(info->width, info->padding);
	if (blank_width == NULL)
		return (NULL);
	if (info->left_aligned == ENABLED)
		ft_strncpy(&blank_width[0], s, s_len);
	else
		ft_strncpy(&blank_width[info->width - s_len], s, s_len);
	return (blank_width);
}

int			print_hexa(t_info *info, char *res)
{
	t_blank	*blank;

	blank = prepare_blank();
	if ((res = process_precision(info, blank->prcs, res)) == NULL
		|| (res = process_width(info, blank->width, res)) == NULL)
	{
		free_blank(blank);
		return (ERROR);
	}
	info->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_blank(blank);
	return (0);
}
