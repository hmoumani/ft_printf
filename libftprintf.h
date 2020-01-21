/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 00:22:12 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 20:22:49 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct		s_flgs
{
	char			conv;
	int				prec;
	int				width;
	char			fill;
	int				plus;
	int				minus;
	int				haspoint;
}					t_flags;
t_flags				g_flags;
int					g_size;
int					ft_atoi(const char *s);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalpha(int c);
char				*ft_itoa(long n);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_tolower(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(long n, int fd);
int					ft_toupper(int c);
int					ft_printf(const char *s, ...);
int					ft_collect_data(const char *s, int *i, va_list *args);
int					ft_printp(va_list *args);
int					ft_prints(va_list *args);
int					ft_printu(va_list *args);
void				ft_printc(va_list *args);
int					ft_printd(va_list *args);
int					ft_printx(va_list *args);
char				*ft_dectohexa(size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_abs(int n);
void				ft_strrev(char *s);
int					ft_getmax(int n, int n1);
void				ft_flags(char **s, int cas);

#endif
