/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:29:35 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:43:58 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define FLAG "-0"
# define TYPE "cspdiuxX%"

# define DIGIT "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# define ENABLED 1
# define DISABLED -1
# define ERROR -1
# define WARNING -1
# define SKIP 0

typedef struct	s_info
{
	int		nbyte;
	int		left_aligned;
	int		width;
	int		prcs;
	int		zero_fill;
	char	padding;
	char	sign;
}				t_info;

typedef struct	s_blank
{
	char *prcs;
	char *width;
}				t_blank;

int				ft_printf(const char *format, ...);
int				format_analyzer(char **fmt, va_list ap, t_info *info);

int				pre_print_char(va_list ap, t_info *info);
int				pre_print_string(va_list ap, t_info *info);
int				pre_print_int(va_list ap, t_info *info);
int				pre_print_unsigned_int(va_list ap, t_info *info);
int				pre_print_hexa(va_list ap, t_info *info, char *base);

int				print_char(t_info *info, char c);
int				print_string(t_info *info, char *res);
int				print_int(t_info *info, char *res);
int				print_unsigned_int(t_info *info, char *res);
int				print_hexa(t_info *info, char *res);
int				print_pointer(va_list ap, t_info *info);
int				print_percent(t_info *info);

t_blank			*prepare_blank(void);
char			*fill_in_blank(int size, char info_padding);
void			free_blank(t_blank *blank);

char			*prepare_sign(t_info *info, char *s);
char			*process_sign(t_info *info, char *blank, int s_len);

#endif
