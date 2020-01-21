/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:23:26 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 00:52:00 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_print_precx(int len, char *s)
{
	int		i;
	int		width;

	width = (flags.prec > len) ? ft_absolute_val(flags.width) - \
	(ft_absolute_val(flags.width) - flags.prec) - 1 : \
	ft_absolute_val(flags.width) - len + 1;
	(flags.prec > 0 && ft_absolute_val(flags.prec) <= len && \
	flags.width > len && flags.fill == '0') ? flags.fill = ' ' : 1;
	i = 0;
	(s[0] == '-') ? width++ : 1;
	if (flags.prec > len && width > 0)
		while (++width < flags.width)
			g_size += write(1, " ", 1);
	else if (flags.width > len)
	{
		while (i++ < flags.width - len)
			g_size += write(1, &flags.fill, 1);
	}
	i = 0;
	while (++i < flags.prec - len + 1)
		g_size += write(1, "0", 1);
	ft_putstr_fd(s, 1);
	if (flags.width * -1 > len + i)
		while (--width > 0 && flags.width < 0)
			g_size += write(1, " ", 1);
}

static	int		ft_printd_x(int size, int num, char *s, int len)
{
	int i;

	i = 0;
	if (flags.haspoint)
		flags.fill = (flags.fill == '0' && flags.prec > len) ? '0' : ' ';
	if (size > 0 && flags.width)
	{
		while (++i < size && !flags.haspoint)
			g_size += write(1, &(flags.fill), 1);
		while (++i <= size && flags.haspoint && flags.width > 0)
			g_size += write(1, " ", 1);
	}
	if (num == 0 && flags.prec == 0 && flags.haspoint && flags.width)
		ft_putchar_fd(' ', 1);
	else if (num == 0 && flags.prec == 0 && flags.haspoint && !flags.width)
		return (1);
	else
		ft_putstr_fd(s, 1);
	if (size < 0 && flags.width && ft_absolute_val(flags.width) > len)
		while (++size < 0)
			g_size += write(1, &(flags.fill), 1);
	return (1);
}

static	void	ft_width_x(char *s, int num)
{
	int		size;
	size_t	len;

	size = 0;
	len = ft_strlen(s);
	if (!flags.prec)
	{
		size = (flags.width > 0) ? flags.width - len + 1 \
		: flags.width + len - 1;
		ft_printd_x(size, num, s, len);
	}
	else
	{
		ft_print_precx((int)len, s);
	}
}

static char		*ft_dectohexax(unsigned int n)
{
	char			*hexadecinum;
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	if (!(hexadecinum = ft_calloc(100, sizeof(char))))
		return (NULL);
	hexadecinum[0] = '0';
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexadecinum[i] = temp + 48;
		else
			hexadecinum[i] = temp + 55;
		n = n / 16;
		if (flags.conv == 'x' || flags.conv == 'p')
			hexadecinum[i] = ft_tolower(hexadecinum[i]);
		i++;
	}
	ft_strrev(hexadecinum);
	return (hexadecinum);
}

void			ft_printx(va_list *args)
{
	size_t	n;
	char	*s;

	n = va_arg(*args, size_t);
	s = ft_dectohexax(n);
	ft_width_x(s, n);
}
