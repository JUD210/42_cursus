/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_6_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:31:07 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_info *info, char *blank_prcs, char *s)
{
	int s_len;

	if (s == NULL && info->prcs != 0)
		s = "0";
	s_len = ft_strlen(s) + ft_strlen("0x");
	blank_prcs = malloc(sizeof(char) * (s_len + 1));
	if (blank_prcs == NULL)
		return (NULL);
	ft_strcpy(blank_prcs, "0x");
	ft_strcpy(&blank_prcs[2], s);
	return (blank_prcs);
}

static char	*process_width(t_info *info, char *blank_width, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (info->width <= s_len)
		return (s);
	blank_width = fill_in_blank(info->width, info->padding);
	if (blank_width == NULL)
		return (NULL);
	if (info->left_aligned == ENABLED)
		ft_strncpy(blank_width, s, s_len);
	else
		ft_strncpy(&blank_width[info->width - s_len], s, s_len);
	return (blank_width);
}

int			print_pointer(va_list ap, t_info *info)
{
	char	*res;
	t_blank	*blank;

	res = ft_lltoa_base(va_arg(ap, long long), HEX_LOWER);
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
