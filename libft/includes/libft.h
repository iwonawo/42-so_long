/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:32:51 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/06 20:08:45 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ************************************************************************** */
/*                                  PRINT                                     */
/* ************************************************************************** */

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long int n);
size_t	ft_base_nbrlen(long long int n, size_t base);
size_t	ft_u_base_nbrlen(unsigned long long int n, size_t base);
int		ft_u_base_putnbr(unsigned long long int n, const char *base);
int		ft_u_puthexa(unsigned long long int n, char format);

/* ************************************************************************** */
/*                                 PRINTF                                     */
/* ************************************************************************** */

int		ft_printf(const char *str, ...);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

char	*ft_itoa(int n);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ************************************************************************** */
/*                              GET NEXT LINE                                 */
/* ************************************************************************** */

# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_move_pointer(char *str);
char	*ft_read_line(char *str);
size_t	ft_end_of_line(char *str, size_t i);
char	*ft_free(char *buff1, char *buff2);

/* ************************************************************************** */
/*                                   LIST                                     */
/* ************************************************************************** */

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
