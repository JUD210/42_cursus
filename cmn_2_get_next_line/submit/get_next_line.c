/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:32:30 by hmin              #+#    #+#             */
/*   Updated: 2020/06/22 17:06:05 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_in_line_from_saved(char **line,
	char **saved_in_fd, char *ptr_nl)
{
	char	*tmp;

	if (ptr_nl != NULL)
	{
		*line = ft_strndup(*saved_in_fd, ptr_nl - *saved_in_fd);
		tmp = ft_strndup(ptr_nl + 1, ft_strlen(ptr_nl + 1));
		free(*saved_in_fd);
		*saved_in_fd = tmp;
		return (SUCCESS);
	}
	if (*saved_in_fd != NULL)
	{
		*line = *saved_in_fd;
		*saved_in_fd = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (EOF_REACHED);
}

int			get_next_line(int fd, char **line)
{
	static char	*saved[MAX_FD];
	char		buff[BUFFER_SIZE + 1];
	int			bytes_rd;
	char		*tmp;
	char		*ptr_nl;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (ERROR);
	while ((ptr_nl = ft_strchr(saved[fd], '\n')) == 0
			&& (bytes_rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes_rd] = 0;
		tmp = (saved[fd] == NULL) ?
			ft_strndup(buff, bytes_rd) : ft_strjoin(saved[fd], buff);
		if (saved[fd] != 0)
			free(saved[fd]);
		saved[fd] = tmp;
	}
	if (bytes_rd < 0)
		return (ERROR);
	return (fill_in_line_from_saved(line, &saved[fd], ptr_nl));
}

/*
** Backup 2020.06.20 15:08:22
**
** int		ptr_nl(char *str)
** {
** 	int	i;
** 	int	nl_idx;
**
** 	i = -1;
** 	nl_idx = -999;
** 	while (str[++i])
** 	{
** 		if (str[i] == '\n')
** 			nl_idx = i;
** 	}
** 	return (nl_idx);
** }
**
** char	*div_saved_by_nl(char **saved)
** {
** 	char	*left;
** 	int		i;
** 	int		j;
**
** 	left = (char *)malloc((BUFFER_SIZE * 2) * sizeof(char));
**
** 	i = -1;
** 	while ((*saved)[++i] != '\n')
** 		left[i] = (*saved)[i];
** 	left[i] = '\0';
**
** 	j = 0;
** 	while ((*saved)[++i])
** 		(*saved)[j++] = (*saved)[i];
** 	(*saved)[j] = '\0';
**
** 	return(left);
** }
**
** // char	*ft_strcat_free_src(char *dst, char *src)
** void	ft_strcat_buff_to_saved(char **saved, char buff[BUFFER_SIZE + 1])
** {
** 	int	i;
** 	int	saved_tail;
**
** 	i = -1;
** 	saved_tail = ft_strlen(*saved);
** 	while (buff[++i])
** 		(*saved)[saved_tail++] = buff[i];
** 	(*saved)[saved_tail] = '\0';
** }
**
** int		get_next_line(int fd, char **line)
** {
** 	static char	*saved;
** 	char		buff[BUFFER_SIZE + 1];
** 	int			nl_idx;
** 	int			bytes_rd;
**
** 	if (saved == NULL)
** 	{
** 		//@@T calloc으로 변경
** 		saved = (char *)malloc((BUFFER_SIZE * 2) * sizeof(char));
** 		int i = 0;
** 		while (i < BUFFER_SIZE * 2 - 1)
** 			saved[i++] = 0;
** 	}
** 	while ((nl_idx = ptr_nl(saved)) < 0)
** 	{
** 		if ((bytes_rd = read(fd, buff, BUFFER_SIZE)) <= 0)
** 			break ;
** 		buff[bytes_rd] = '\0';
** 		ft_strcat_buff_to_saved(&saved, buff); // saved += buff
** 	}
**
** 	if (bytes_rd > 0)
** 	{
** 		*line = div_saved_by_nl(&saved);
** 		return (SUCCESS);
** 	}
** 	else if (bytes_rd < 0)
** 		return (ERROR);
** 	*line = saved;
** 	// or strdup saved to line, and free saved
** 	return (EOF_REACHED);
**
** 	// line = saved[0 .. nl_idx];
** }
**
** // int		get_next_line2(int fd, char **line)
** // {
** // 	static char	*saved;
** // 	char		*buff;
** // 	int			buff_len;
** // 	int			nl_idx;
**
** // 	if (saved == NULL)
** // 		saved = (char *)malloc((BUFFER_SIZE * 2) * sizeof(char));
** // 	*line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
**
**
** // 	buff_len = (int)read(fd, *line, BUFFER_SIZE);
**
**
** // 	//@@D buff_len 기준이 아니다. saved 기준.
** // 	(*line)[buff_len] = '\0';
**
** // 	if (buff_len > 0)
** // 		return (SUCCESS);
** // 	else if (buff_len == 0)
** // 		return (EOF_REACHED);
** // 	return (ERROR);
** // }
*/
