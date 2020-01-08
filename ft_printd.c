/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:15:57 by hmoumani          #+#    #+#             */
/*   Updated: 2019/12/27 20:50:20 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(char *s)
{
	int		size;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	size = (flags.width > 0) ? flags.width - len + 1 : flags.width + len - 1;
	if (size > 0 && flags.width)
		while (++i < size)
			g_size += write(1, &(flags.fill), 1);
	ft_putstr_fd(s, 1);
	if (size < 0 && flags.width)
		while (++size < 0)
			g_size += write(1, &(flags.fill), 1);
}

void	ft_printd(va_list *args)
{
	char *s;

	s = ft_itoa(va_arg(*args, int));
	ft_width(s);
}
