/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:59:46 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/20 16:09:26 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putp_fd(char *s, int fd, int prec)
{
	int i;

	i = 0;
	prec  = ft_absolute_val(prec);
	ft_putstr_fd("0x", 1);
	while (s[i])
	{
		g_size += write(fd, &s[i++], 1);
	}
}

void	ft_width_p(char *s, int len)
{
	int width;

	width = (flags.width >= len) ? flags.width - len: flags.width + len;
	(flags.minus && flags.haspoint) ? width = (-1 * width) + 1: 1;
	if (flags.width >= len && flags.width)
		while (--width >= 0)
			ft_putchar_fd(' ', 1);
	ft_putp_fd(s, 1, flags.prec);
	if ((flags.minus || (!flags.haspoint && flags.width < 0)))
		while (++width <= 0)
			ft_putchar_fd(' ', 1);
}

void	ft_strrev(char *s)
{
	char	temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i <= len / 2)
	{
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
		i++;
	}
}

char	*ft_dectohexa(size_t n)
{
	char	*hexadecinum;
	size_t	i;
	size_t	temp;

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

void	ft_printp(va_list *args)
{
	size_t			p;
	char			*s;

	p = va_arg(*args, size_t);
	s = ft_dectohexa(p);
	(flags.prec < 0) ? flags.haspoint = 0 : 1;
	if (!s)
	{
		s = ft_strdup("(null)");
	}
	ft_width_p(s, (int)ft_strlen(s) + 2);
}
