/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:05:31 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/20 17:50:18 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puts_fd(char *s, int fd, int prec)
{
	int i;

	i = 0;
	prec  = ft_absolute_val(prec);
	while (s[i] && (i < prec || !flags.haspoint))
	{
		g_size += write(fd, &s[i++], 1);
	}
}

void	ft_width_s(char *s, int len)
{
	int width;

	len  = (len > flags.prec && flags.haspoint) ? flags.prec : len;
	width = (flags.width >= len) ? flags.width - len: flags.width + len;
	if (flags.width >= len && flags.width)
		while (--width >= 0)
			ft_putchar_fd(' ', 1);
	ft_puts_fd(s, 1, flags.prec);
	if (flags.width < len && flags.width)
		while (++width <= 0)
			ft_putchar_fd(' ', 1);
}

void	ft_prints(va_list *args)
{
	char *s;

	s = va_arg(*args, char *);
	(flags.prec < 0) ? flags.haspoint = 0 : 1;
	if (!s)
	{
		s = ft_strdup("(null)");
	}
	ft_width_s(s, (int)ft_strlen(s));
}
