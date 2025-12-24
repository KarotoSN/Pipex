/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:41:26 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 11:06:40 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t count);
int					ft_toupper(int c);
char				*ft_strchr(const char *string, int searchedChar);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				**ft_split(char const *s, char c);
void				ft_putendl_fd(char *s, int fd);
int					ft_atoi(const char *str);
void				*ft_memchr(const void *s1, int searchedChar, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *str1, const char *str2,
						size_t length);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int charset);
void				*ft_memset(void *ptn, int value, size_t count);
void				ft_bzero(void *ptn, size_t count);
void				*ft_calloc(size_t elementCount, size_t elementSize);
void				*ft_memcpy(void *dest, const void *src, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);

#endif