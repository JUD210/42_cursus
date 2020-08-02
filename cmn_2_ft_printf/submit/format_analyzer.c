/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:29:18 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(char **fmt, t_info *info)
{
	while (is_in_set(**fmt, FLAG))
	{
		**fmt == '-' ? info->left_aligned = ENABLED : SKIP;
		**fmt == '0' ? info->zero_fill = ENABLED : SKIP;
		(*fmt)++;
	}
}

static void	parse_width(char **fmt, va_list ap, t_info *info)
{
	char *dup;

	if (!(**fmt == '*' || is_in_set(**fmt, DIGIT)))
		return ;
	if (**fmt == '*')
	{
		info->width = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		dup = ft_strndup(*fmt, ft_strlen(*fmt));
		info->width = ft_atoi(dup);
		free(dup);
		while (is_in_set(**fmt, DIGIT))
			(*fmt)++;
	}
	if (info->width < 0)
	{
		info->left_aligned = ENABLED;
		info->width = -info->width;
	}
}

static void	parse_precision(char **fmt, va_list ap, t_info *info)
{
	char *dup;

	if (**fmt != '.')
		return ;
	(*fmt)++;
	if (**fmt == '*')
	{
		info->prcs = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		dup = ft_strndup(*fmt, ft_strlen(*fmt));
		info->prcs = ft_atoi(dup);
		free(dup);
		while (is_in_set(**fmt, DIGIT))
			(*fmt)++;
	}
	if (info->prcs < 0)
		info->prcs = DISABLED;
}

int			format_analyzer(char **fmt, va_list ap, t_info *info)
{
	if (**fmt == '\0')
		return (ERROR);
	parse_flags(fmt, info);
	parse_width(fmt, ap, info);
	parse_precision(fmt, ap, info);
	if (is_in_set(**fmt, TYPE) == FALSE)
		return (ERROR);
	return (0);
}
