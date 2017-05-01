/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:41:47 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 16:01:58 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};
typedef struct s_list	t_list;

struct	s_tree
{
	void				*value;
	struct s_tree	*tgauche;
	struct s_tree	*tdroit;
	struct s_tree	*parent;
};
typedef	struct s_tree	t_tree;

t_tree	*ft_creer_tree(void *nb);
void	ft_creer_noeud(t_tree **arbre, t_tree **parent, void *value);
void	ft_effacer_tree(t_tree *arbre);
void	ft_ajouterdata_tree(t_tree **arbre, void *nb);
void	ft_afficher_tree(t_tree *a);
int		ft_contnoeud_tree(t_tree *a);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int nbr);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_swap(int *a, int *b);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_strclr(char *s);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_strdel(char **as);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_longlimit(long nb);
int		ft_strlen(char *str);
int		ft_intlen(long nb);
int		ft_strlen_tool(char *str, char c, int nb, int nbr);
int		ft_intlimit(int nb);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isnum(int c);
int		ft_isalnum(int c);
int		ft_isesp(char c);
int		ft_isprint(int c);
int		ft_isnumeric(int c);
int		ft_isascii(int c);
int		ft_strlcat(char *dest, char *src, int nb);
int		ft_toupper(int c);
int		ft_tolower(int c);

char	**ft_strsplit(char const *s, char c);
char	*ft_strtrim(const char *s);
char	*ft_itoa(int nb);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int n);
char	*ft_strstr(char *str, const char *to_find);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strnstr(char *str, const char *to_find, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list	*ft_lstnew(void const *content, size_t content_size);
#endif
