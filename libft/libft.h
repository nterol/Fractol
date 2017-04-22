/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:16:48 by nterol            #+#    #+#             */
/*   Updated: 2017/04/21 17:04:28 by nterol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# define CHAR '\n'
# define FD_SIZE 4096

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(char *str);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
size_t				ft_strlen(const char *str);
void				ft_putchar(char c);
void				ft_putchar_fd(const char s, int fd);
void				ft_putnbr(int n);
void				ft_putnbrendl(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *src, char *dest, unsigned int n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(char const *str, char const *to_find, size_t n);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strdup(char *src);
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *str, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *t, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_itoa(int nb);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *str, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int n);
char				*ft_strrchr(const char *str, int n);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinch(char const *str, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstprint(t_list *lst);
void				ft_lstaddback(t_list *lst, t_list *new);
void				ft_print_bits(size_t octet);
unsigned char		ft_swapbits(unsigned char octet);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_iterative_factorial(int nb);
int					get_next_line(const int fd, char **line);
double				ft_count(char **ptr);

#endif
