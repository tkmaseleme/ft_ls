/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:29:50 by tmaselem          #+#    #+#             */
/*   Updated: 2018/11/01 10:03:15 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100
# define TRUE 1
# define FALSE 0
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <wchar.h>
# include <limits.h>
# include <stdarg.h>
# include <dirent.h>

# define ABS(x) ((x < 0) ? -(x) : (x))

/*
** COLOURS
*/

# define DEF          "\033[0m"
# define BOLD         "\033[1m"
# define BLACK        "\033[30m"
# define RED          "\033[31m"
# define GREEN        "\033[32m"
# define BROWN        "\033[33m"
# define BLUE         "\033[34m"
# define MAGENTA      "\033[35m"
# define CYAN         "\033[36m"
# define GRAY         "\033[37m"

/*
** Error Flags
*/

enum { NO_ERROR, USER, MEMORY };

/*
** Boolean types
*/

typedef enum		e_bool
{
	false, true
}					t_bool;

/*
** Directions and indexes
*/

typedef struct		s_extra
{
	int		i;
	int		j;
	int		x;
	int		y;
	t_bool	it;
	DIR		*dir;
	char	*buf;
	char	*tmp;
}					t_extra;

/*
** Space identifiers
*/

typedef struct		s_space
{
	int	min;
	int	max;
	int	size;
	int	gsize;
	int	usize;
	int	lsize;
	int	total;
}					t_space;

/*
** ft_printf stuff
*/

typedef struct		s_flist
{
	char	*flags;
	short	width;
	short	prcsn;
	char	hh;
	char	h;
	char	ll;
	char	l;
	char	j;
	char	z;
	char	specifier;
	short	size;
}					t_flist;

/*
** list stuff
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** List Functions
*/

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(*f)(t_list *item));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpshbck(t_list **lst, const void *content,\
		size_t content_size);

/*
** Output Functions
*/

int					ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar_error(int c);
int					ft_putstr(const char *str);
void				ft_putstr_error(char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putnbr(long long num);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);

/*
** String Manipulation Functions
*/

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strupper(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strndup(const char *s, size_t n);
size_t				ft_strlen(const char *str);

/*
** Checking Functions
*/

int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					*ft_iswhitespace(int c);
int					ft_strcasecmp(const char *s1, const char *s2);

/*
** More Strings
*/

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

/*
** Memory Functions
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);

/*
** Input
*/

int					get_next_line(const int fd, char **line);
char				*ft_itoa(int n);
char				*ft_itoa_base(int num, int base);
int					ft_getopt(int ac, char **av, const char *opt, char **res);
int					ft_atoi(const char *str);

/*
** ft_printf functions
*/

int					ft_printf(char *format, ...);
int					ft_fnscall(char **input, va_list va);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_atoif(char **str1);
char				ft_strchrf(char *str0, int form00);
void				ft_strdel(char **as);
int					ft_putstrf(char *str, int prcsn);
int					ft_putprcnt(t_flist *lst, char p);
int					ft_chrhandle(t_flist *lst, void *c);
int					ft_strhandle(t_flist *lst, void *s);
int					ft_putwchar(wchar_t wc);
int					ft_putwstr(wchar_t *ws, int prcsn);
int					ft_dgthandle(t_flist *lst, void *n00);
int					ft_unshandle(t_flist *lst, void *n01);
int					ft_octhandle(t_flist *lst, void *n10);
int					ft_hexhandle(t_flist *lst, void *n11);
int					ft_ptrhandle(t_flist *lst, void *n);
int					ft_output(t_flist *lst, va_list va);

/*
** Miscelleanous
*/

void				nerror(char *error, char *name, int e);
void				do_space_thing(t_space *things);
#endif
