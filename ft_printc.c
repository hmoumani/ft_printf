/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:11:35 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/20 23:30:32 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_width_c(char c)
{
	(flags.minus && flags.width > 0) ? flags.width = flags.width * -1 : 1;
	while (--flags.width > 0)
		ft_putchar_fd(flags.fill, 1);
	ft_putchar_fd(c, 1);
	while (++flags.width + 1 < 0)
		ft_putchar_fd(' ', 1);
}

void	ft_printc(va_list *args)
{
	char c;

	c = '%';
	if (flags.conv == 'c')
		c = va_arg(*args, int);
	ft_width_c(c);
}
