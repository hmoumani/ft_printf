/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:11:35 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 03:26:14 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_width_c(char c)
{
	(g_flags.minus && g_flags.width > 0) ? \
	g_flags.width = g_flags.width * -1 : 1;
	while (--g_flags.width > 0)
		ft_putchar_fd(g_flags.fill, 1);
	ft_putchar_fd(c, 1);
	while (++g_flags.width + 1 < 0)
		ft_putchar_fd(' ', 1);
}

void	ft_printc(va_list *args)
{
	char c;

	c = '%';
	if (g_flags.conv == 'c')
		c = va_arg(*args, int);
	ft_width_c(c);
}
