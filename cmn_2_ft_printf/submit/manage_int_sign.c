/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:00:55 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepare_sign(t_info *info, char *s)
{
	if (s[0] == '-')
	{
		info->sign = '-';
		s++;
	}
	return (s);
}

char	*process_sign(t_info *info, char *blank, int s_len)
{
	if (info->sign == '\0')
		return (blank);
	if ((info->zero_fill == ENABLED && info->prcs == DISABLED)
			|| info->left_aligned == ENABLED)
		blank[0] = info->sign;
	else
		blank[info->width - s_len - 1] = info->sign;
	return (blank);
}
