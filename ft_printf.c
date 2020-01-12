/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:41:45 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/11 18:33:57 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(void)
{
	flags = (t_flags){ 0, 0, 0, ' '};
}

void	ft_redirect_conversion(va_list *args)
{
	if (flags.conv == 'd' || flags.conv == 'i')
		ft_printd(args);
	if (flags.conv == 's')
		ft_prints(args);
	if (flags.conv == 'c')
		ft_printc(args);
	if (flags.conv == 'u')
		ft_printu(args);
	if (flags.conv == 'p')
		ft_printp(args);
	if (flags.conv == 'x' || flags.conv == 'X')
		ft_printxX(args);
}

int		ft_printf(const char *s, ...)
{
	int		i;
	va_list args;

	i = 0;
	g_size = 0;
	va_start(args, s);
	// while (s[i])
	// {
		ft_init_flags();
		// if (s[i] != '%')
		// 	ft_putchar_fd(s[i], 1);
		// else
		// {
		ft_collect_data(s, &i, &args);
		printf("conv : %c , prec : %d , width : %d , fill : %c",flags.conv, flags.prec, flags.width, flags.fill);
			// ft_redirect_conversion(&args);
		// }
		i++;
	// }
	return (g_size);
}

