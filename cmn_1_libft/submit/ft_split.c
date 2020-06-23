/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:11:06 by hmin              #+#    #+#             */
/*   Updated: 2020/04/18 04:06:00 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "     aaa    b  cd e     "
** "     aaa    b  cd e"
** "aaa    b  cd e"
**
** -> {"aaa", "b", "cd", "e", "\0"}
***************************************
** "\0" -> NULL
** "    \0" -> NULL
** "a\0" -> "a"
** "   a\0" -> "a"
*/

/*
** Answer
*/

#include "libft.h"

static char		*ft_strndup(const char *src, size_t n)
{
	char	*strs;
	size_t	i;

	strs = NULL;
	if (!(strs = (char*)malloc(sizeof(*strs) * n + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		strs[i] = src[i];
		i++;
	}
	strs[i] = '\0';
	return (strs);
}

static int		count_row(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] != c)
		j = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c && (str[i + 1] != c && str[i + 1] != '\0'))
			j++;
		i++;
	}
	return (j);
}

static void		free_strs(char **strs)
{
	int j;

	j = 0;
	while (strs[j] != NULL)
	{
		free(strs[j]);
		j++;
	}
}

char			**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		index;
	char	**strs;

	i = 0;
	j = 0;
	if (str == NULL ||
	(!(strs = malloc(sizeof(*strs) * count_row((char *)str, c) + 1))))
		return (NULL);
	while (str[i] != '\0' && j < count_row((char*)str, c))
	{
		index = 0;
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			index++;
			i++;
		}
		if ((strs[j++] = ft_strndup(str + i - index, index)) == NULL)
			free_strs(strs);
	}
	strs[j] = 0;
	return (strs);
}

/*
** My previous code...
*/

/*
** static int	compute_strs_len(const char *str, char dl)
** {
** 	int	strs_len;
** 	int	i;
**
** 	strs_len = 0;
** 	i = -1;
** 	while (str[++i])
** 		if (str[i] != dl)
** 			if (str[i + 1] == dl || str[i + 1] == '\0')
** 				strs_len++;
** 	return (strs_len);
** }
**
** static void	split_str_to_strs(const char *str, char dl, char **strs)
** {
** 	char	*sub_str;
** 	int		sub_str_len;
** 	int		strs_i;
** 	int		i;
**
** 	strs_i = 0;
** 	i = -1;
** 	while (str[++i])
** 	{
** 		if (str[i] != dl)
** 		{
** 			sub_str_len++;
** 			if (str[i + 1] == dl || str[i + 1] == '\0')
** 			{
** 				if (!(sub_str = ft_calloc((sub_str_len + 1), sizeof(char))))
** 				{
** 					return ;
** 				}
** 				ft_memcpy(sub_str, &str[i - sub_str_len + 1], sub_str_len);
** 				strs[strs_i] = sub_str;
** 				strs_i++;
** 				sub_str_len = 0;
** 			}
** 		}
** 	}
** }
**
** char		**ft_split(const char *str, char dl)
** {
** 	char	**strs;
** 	int		strs_len;
**
** 	strs_len = compute_strs_len(str, dl);
** 	strs = (char **)malloc((strs_len + 1) * sizeof(char *));
** 	if (!str || !strs)
** 		return (NULL);
** 	split_str_to_strs(str, dl, strs);
** 	strs[strs_len] = NULL;
** 	return (strs);
** }
*/

/*
**	if (strs_len == 0)
**		return (NULL);
**
**	NO, IT's NOT! You should return a 'strs' with 'a' 'NULL item'!
**	Return NULL Only when allocating was failed.
*/
