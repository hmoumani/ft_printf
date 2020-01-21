/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:59:46 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 03:28:06 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putp_fd(char *s, int fd, size_t p)
{
	int i;

	i = 0;
	if (!p && g_flags.haspoint)
	{
		ft_putstr_fd("0x", 1);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		while (s[i])
		{
			g_size += write(fd, &s[i++], 1);
		}
	}
}

void	ft_width_p(char *s, int len, size_t p)
{
	int width;

	width = (g_flags.width >= len) ? g_flags.width - len : g_flags.width + len;
	if (!p && g_flags.haspoint && width > 0)
		width++;
	else if (!p && g_flags.haspoint && width < 0)
		width--;
	(g_flags.minus && g_flags.width > 0) ? width = (-1 * width) + 1 : 1;
	if (g_flags.width >= len && g_flags.width)
		while (--width >= 0)
			ft_putchar_fd(' ', 1);
	ft_putp_fd(s, 1, p);
	if (((g_flags.width < 0 || (g_flags.minus && g_flags.haspoint)) || \
	(g_flags.haspoint && g_flags.width < 0)) && g_flags.width)
		while (++width <= 0)
			ft_putchar_fd(' ', 1);
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
		if (g_flags.conv == 'x' || g_flags.conv == 'p')
			hexadecinum[i] = ft_tolower(hexadecinum[i]);
		i++;
	}
	ft_strrev(hexadecinum);
	return (hexadecinum);
}

int		ft_printp(va_list *args)
{
	size_t			p;
	char			*s;

	p = va_arg(*args, size_t);
	if (!(s = ft_dectohexa(p)))
		return (0);
	(g_flags.prec < 0) ? g_flags.haspoint = 0 : 1;
	ft_width_p(s, (int)ft_strlen(s) + 2, p);
	free(s);
	return (1);
}
