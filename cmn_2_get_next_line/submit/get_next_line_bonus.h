/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:33:54 by hmin              #+#    #+#             */
/*   Updated: 2020/06/22 17:07:35 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# ifndef MAX_FD
#  define MAX_FD 10000
# endif

# define SUCCESS 1
# define EOF_REACHED 0
# define ERROR -1

int		get_next_line(int fd, char **line);

int		ft_strlen(char *c);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(char *s1, int size);
char	*ft_strjoin(char *s1, char *s2);

#endif
