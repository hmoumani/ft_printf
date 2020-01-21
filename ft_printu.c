/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:08:49 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 20:15:50 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_precu(int len, char *s)
{
	int		i;
	int		width;

	width = (g_flags.prec > len) ? ft_abs(g_flags.width) - \
	(ft_abs(g_flags.width) - g_flags.prec) - 1 : \
	ft_abs(g_flags.width) - len + 1;
	(g_flags.prec > 0 && ft_abs(g_flags.prec) <= len && \
	g_flags.width > len && g_flags.fill == '0') ? g_flags.fill = ' ' : 1;
	i = 0;
	if (g_flags.prec > len && width > 0)
		while (++width < g_flags.width)
			g_size += write(1, " ", 1);
	else if (g_flags.width > len)
	{
		while (i++ < g_flags.width - len)
			g_size += write(1, &g_flags.fill, 1);
	}
	i = 0;
	while (++i < g_flags.prec - len + 1)
		g_size += write(1, "0", 1);
	ft_putstr_fd(s, 1);
	if (g_flags.width * -1 > len + i)
		while (--width > 0 && g_flags.width < 0)
			g_size += write(1, " ", 1);
}

int		ft_printd_u(int size, int num, char *s, int len)
{
	int i;

	i = 0;
	if (g_flags.haspoint)
		g_flags.fill = (g_flags.fill == '0' && g_flags.prec > len) ? '0' : ' ';
	if (size > 0 && g_flags.width)
	{
		while (++i < size && !g_flags.haspoint)
			g_size += write(1, &(g_flags.fill), 1);
		while (++i <= size && g_flags.haspoint && g_flags.width > 0)
			g_size += write(1, " ", 1);
	}
	if (num == 0 && g_flags.prec == 0 && g_flags.haspoint && g_flags.width)
		ft_putchar_fd(' ', 1);
	else if (num == 0 && g_flags.prec == 0 && \
	g_flags.haspoint && !g_flags.width)
		return (1);
	else
		ft_putstr_fd(s, 1);
	if (size < 0 && g_flags.width && ft_abs(g_flags.width) > len)
		while (++size < 0)
			g_size += write(1, &(g_flags.fill), 1);
	return (1);
}

void	ft_width_u(char *s, int num)
{
	int		size;
	size_t	len;

	size = 0;
	len = ft_strlen(s);
	if (!g_flags.prec)
	{
		size = (g_flags.width > 0) ? g_flags.width - len + 1 \
		: g_flags.width + len - 1;
		ft_printd_u(size, num, s, len);
	}
	else
	{
		ft_print_precu((int)len, s);
	}
}

int		ft_printu(va_list *args)
{
	unsigned int	u;
	char			*s;

	u = va_arg(*args, unsigned int);
	if (!(s = ft_itoa(u)))
		return (0);
	ft_width_u(s, u);
	free(s);
	return (1);
}
