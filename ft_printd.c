/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:15:57 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/18 21:08:17 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_prec(int len, char *s)
{
	int		i;
	int		width;

	width = (flags.prec > len) ? ft_absolute_val(flags.width) - flags.prec \
	: ft_absolute_val(flags.width) - len;
	i = 0;
	if (flags.prec > len && width > 0)
		while (++width < flags.width - 1)
			g_size += write(1, " ", 1);
	else if (flags.width > len)
		while (i++ < flags.width - len)
			g_size += write(1, " ", 1);
	i = 0;
	while (++i < flags.prec - len + 1)
		g_size += write(1, "0", 1);
	ft_putstr_fd(s, 1);
	if (flags.prec > len && flags.prec > len + i)
		while (--width > 0)
			g_size += write(1, " ", 1);
}

void	ft_printd_f(int size, int num, char *s)
{
	int i;

	i = 0;
	if (size > 0 && flags.width)
	{
		if (num < 0 && flags.fill == '0')
		{
			g_size += write(1, "-", 1);
			num *= -1;
			s++;
		}
		while (++i < size)
			g_size += write(1, &(flags.fill), 1);
	}
	if (num == 0 && flags.prec == 0 && flags.haspoint)
		ft_putchar_fd(' ',1);
	else
		ft_putstr_fd(s, 1);
	if (size < 0 && flags.width)
		while (++size < 0)
			g_size += write(1, &(flags.fill), 1);
}

void	ft_width(char *s, int num)
{
	int		size;
	size_t	len;

	size = 0;
	len = ft_strlen(s);
	if (!flags.prec)
	{
		size = (flags.width > 0) ? flags.width - len + 1 \
		: flags.width + len - 1;
		ft_printd_f(size, num, s);
	}
	else
	{
		ft_print_prec((int)len, s);
	}
}

void	ft_printd(va_list *args)
{
	char	*s;
	int		num;

	num = va_arg(*args, int);
	s = ft_itoa(num);
	ft_width(s, num);
}
