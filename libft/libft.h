/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:27:41 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/27 14:38:35 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct		s_dnode
{
	int				*x;
	int				y;
	int				len_x;
	struct s_dnode	*p_next;
	struct s_dnode	*p_prev;
}					t_dnode;

typedef struct		s_dlist
{
	unsigned int	length;
	t_dnode	*p_head;
	t_dnode	*p_tail;
}					t_dlist;


void			*ft_memset(void *s, int c, unsigned int n);
void			*ft_bzero(void *s, unsigned int n);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memccpy(void *dest, const void *src, int c, unsigned int n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memchr(const void *s, int c, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
unsigned int	ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int n);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
char			*ft_strnstr(const char *large, const char *small,
					unsigned int n);
int				ft_atoi(const char *str);
void			*ft_calloc(unsigned int count, unsigned int size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_checkspace(int c);
t_dnode				*ft_dlistaddh(t_dlist **p_list);
t_dnode				*ft_dlistaddt(t_dlist **p_list);
t_dlist				*ft_dlistnew(void);
int				ft_dlistdel(t_dlist **p_list, int errcode);

#endif
