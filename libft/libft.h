/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:26:44 by hmin              #+#    #+#             */
/*   Updated: 2020/04/16 18:12:10 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*
** # define UCHAR unsigned char
** # define UINT unsigned int
** # define UL unsigned long
**
** # define IS_SPACE(c) (c==' '||c=='\t'||c=='\n'||c=='\r'||c=='\f'||c=='\v')
*/

/*
**	content : The data contained in the element.
**			  The void * allows to store any kind of data.
**	next : The next element’s address or NULL if it’s the last element.
*/

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
**	Part 1
*/

void			*ft_memset(void *dst, int src, size_t len);
void			ft_bzero(void *dst, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);

size_t			ft_strlen(const char *s);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);

void			*ft_calloc(size_t number, size_t size);
char			*ft_strdup(const char *str);

/*
**	Part 2
*/

char			*ft_substr(char const *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *str, const char *set);
char			**ft_split(const char *str, char dl);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	Part Bonus
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **p_head, t_list *new);
int				ft_lstsize(t_list *head);
t_list			*ft_lstlast(t_list *head);
void			ft_lstadd_back(t_list **p_head, t_list *new);
void			ft_lstdelone(t_list *list, void (*del)(void *));
void			ft_lstclear(t_list **p_curr, void (*del)(void *));
void			ft_lstiter(t_list *curr, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));

#endif
