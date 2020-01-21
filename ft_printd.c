/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:15:57 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 19:54:08 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_first_part(int len, int *width, char **s)
{
	int i;

	i = 0;
	*width = (g_flags.prec > len) ? ft_absolute_val(g_flags.width) - \
	(ft_absolute_val(g_flags.width) - g_flags.prec) - 1 : \
	ft_absolute_val(g_flags.width) - len + 1;
	(g_flags.prec > 0 && ft_absolute_val(g_flags.prec) <= len \
	&& g_flags.width > len && g_flags.fill == '0') ? g_flags.fill = ' ' : 1;
	i = 0;
	(*s[0] == '-') ? (*width)++ : 1;
	(*s[0] == '-' && g_flags.fill < '0' && g_flags.prec >= len) ? i++ : 1;
	if (g_flags.prec > len && (*width) > 0)
		while (++(*width) < g_flags.width)
			g_size += write(1, " ", 1);
	else if (g_flags.width > len)
	{
		if (*s[0] == '-' && g_flags.width > len && \
		ft_absolute_val(g_flags.prec) && g_flags.fill == '0')
		{
			(*s)++;
			ft_putchar_fd('-', 1);
			width--;
		}
		while (i++ < g_flags.width - len)
			g_size += write(1, &g_flags.fill, 1);
	}
}

void		ft_print_prec(int len, char *s)
{
	int		i;
	int		width;
	int		opt;

	opt = 0;
	ft_first_part(len, &width, &s);
	i = 0;
	if (s[0] == '-')
	{
		s++;
		opt = 1;
		ft_putchar_fd('-', 1);
		if (ft_absolute_val(g_flags.width) <= ft_absolute_val(g_flags.prec))
			width--;
		i--;
	}
	while (++i < g_flags.prec - len + 1)
		g_size += write(1, "0", 1);
	ft_putstr_fd(s, 1);
	(len < g_flags.prec && g_flags.width < 0 && g_flags.prec > 0 && ft_absolute_val(g_flags.width) > \
	g_flags.prec) ? width = ft_absolute_val(g_flags.width) - ft_getmax(g_flags.prec, len) + 1: 1;
	(opt && ft_absolute_val(g_flags.width) > ft_absolute_val(g_flags.prec)) ? width -- : 1;
	if (g_flags.width * -1 > len + i)
		while (--width > 0 && g_flags.width < 0)
			g_size += write(1, " ", 1);
}

int			ft_printd_f(int size, int num, char *s, int i)
{
	int len;

	len = ft_strlen(s);
	if (size > 0 && g_flags.width)
	{
		if (num < 0 && g_flags.fill == '0' && !g_flags.haspoint)
		{
			g_size += write(1, "-", 1);
			num *= -1;
			s++;
		}
		(g_flags.width < len && s[0] == '-') ? i++ : 1;
		while (++i < size && !g_flags.haspoint)
			g_size += write(1, &(g_flags.fill), 1);
		while (++i <= size && g_flags.haspoint)
			g_size += write(1, " ", 1);
	}
	if (num == 0 && g_flags.prec == 0 && g_flags.haspoint && g_flags.width)
		ft_putchar_fd(' ', 1);
	else if (num == 0 && g_flags.prec == 0 && \
	g_flags.haspoint && !g_flags.width)
		return (1);
	else
		ft_putstr_fd(s, 1);
	if (size < 0 && g_flags.width && g_flags.width < 0)
		while (++size < 0)
			g_size += write(1, &(g_flags.fill), 1);
	return (1);
}

void		ft_width(char *s, int num)
{
	int		size;
	size_t	len;

	size = 0;
	len = ft_strlen(s);
	if (!g_flags.prec)
	{
		if (g_flags.haspoint)
			g_flags.fill = (g_flags.fill == '0' && g_flags.prec > \
			(int)len) ? '0' : ' ';
		size = (g_flags.width > 0) ? g_flags.width - len + 1 \
		: g_flags.width + len - 1;
		ft_printd_f(size, num, s, 0);
	}
	else
	{
		ft_print_prec((int)len, s);
	}
}

int			ft_printd(va_list *args)
{
	char	*s;
	int		num;

	num = va_arg(*args, int);
	if (!(s = ft_itoa(num)))
		return (0);
	ft_width(s, num);
	return (1);
}
