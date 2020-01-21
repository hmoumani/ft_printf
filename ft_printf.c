/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:41:45 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 03:26:39 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_flags(void)
{
	g_flags = (t_flags){ 0, 0, 0, ' ', 0, 0, 0};
}

int		ft_redirect_conversion(va_list *args)
{
	if (g_flags.conv == 'd' || g_flags.conv == 'i')
		if (!(ft_printd(args)))
			return (0);
	if (g_flags.conv == 's')
		if (!(ft_prints(args)))
			return (0);
	if (g_flags.conv == 'c' || g_flags.conv == '%')
		ft_printc(args);
	if (g_flags.conv == 'u')
		if (!(ft_printu(args)))
			return (0);
	if (g_flags.conv == 'p')
		if (!(ft_printp(args)))
			return (0);
	if (g_flags.conv == 'x' || g_flags.conv == 'X')
		if (!(ft_printx(args)))
			return (0);
	return (1);
}

int		ft_printf(const char *s, ...)
{
	int		i;
	va_list args;

	i = 0;
	g_size = 0;
	va_start(args, s);
	while (s[i])
	{
		ft_init_flags();
		if (s[i] != '%')
			ft_putchar_fd(s[i], 1);
		else
		{
			if (!ft_collect_data(s, &i, &args))
				return (-1);
			if (!ft_redirect_conversion(&args))
				return (-1);
		}
		i++;
	}
	return (g_size);
}
