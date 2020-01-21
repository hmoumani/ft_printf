/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:05:31 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 03:26:49 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puts_fd(char *s, int fd, int prec)
{
	int i;

	i = 0;
	prec = ft_absolute_val(prec);
	while (s[i] && (i < prec || !g_flags.haspoint))
	{
		g_size += write(fd, &s[i++], 1);
	}
}

void	ft_width_s(char *s, int len)
{
	int width;

	len = (len > g_flags.prec && g_flags.haspoint) ? g_flags.prec : len;
	width = (g_flags.width >= len) ? g_flags.width - len : g_flags.width + len;
	if (g_flags.width >= len && g_flags.width)
		while (--width >= 0)
			ft_putchar_fd(' ', 1);
	ft_puts_fd(s, 1, g_flags.prec);
	if (g_flags.width < len && g_flags.width)
		while (++width <= 0)
			ft_putchar_fd(' ', 1);
}

int		ft_prints(va_list *args)
{
	char *s;

	s = va_arg(*args, char *);
	(g_flags.prec < 0) ? g_flags.haspoint = 0 : 1;
	if (!s)
	{
		if (!(s = ft_strdup("(null)")))
			return (0);
		ft_width_s(s, (int)ft_strlen(s));
		free(s);
	}
	else
	{
		ft_width_s(s, (int)ft_strlen(s));
	}
	return (1);
}
