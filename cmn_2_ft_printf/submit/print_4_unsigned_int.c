/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_4_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:30:58 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_info *info, char *blank_prcs, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (s[0] == '0' && info->prcs == 0)
		s = "";
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
	if (info->sign == '\0' && info->width < s_len)
		return (s);
	if (info->zero_fill == ENABLED &&
			info->prcs == DISABLED && info->left_aligned == DISABLED)
		info->padding = '0';
	if (info->width < s_len)
		info->width = s_len;
	if (info->sign && info->width == s_len)
		info->width++;
	blank_width = fill_in_blank(info->width, info->padding);
	if (blank_width == NULL)
		return (NULL);
	if (info->left_aligned == ENABLED && info->sign)
		ft_strncpy(blank_width + 1, s, s_len);
	else if (info->left_aligned == ENABLED)
		ft_strncpy(blank_width, s, s_len);
	else
		ft_strncpy(&blank_width[info->width - s_len], s, s_len);
	return (process_sign(info, blank_width, s_len));
}

int			print_unsigned_int(t_info *info, char *res)
{
	t_blank *blank;

	blank = prepare_blank();
	res = prepare_sign(info, res);
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
