/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:15:57 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/17 22:46:59 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		size = (flags.width > 0) ? flags.width - len + 1 \
		: flags.width + len - 1;
	else
		size = (flags.width > 0) ? flags.prec - len + 1 \
		: flags.prec + len - 1;
	ft_printd_f(size, num, s);
}

void	ft_printd(va_list *args)
{
	char	*s;
	int		num;

	num = va_arg(*args, int);
	s = ft_itoa(num);
	ft_width(s, num);
}
