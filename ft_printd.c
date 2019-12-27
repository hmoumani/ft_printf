/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:15:57 by hmoumani          #+#    #+#             */
/*   Updated: 2019/12/23 17:16:26 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(char *s)
{
	int size;
	int i;

	i = 0;
	size = flags.width - ft_strlen(s) + 1;
	while (++i < size)
		write(1," ",1);
}

void	ft_printd(va_list *args)
{
	char *s;
	// char *p;

	s = ft_itoa(va_arg(*args, int));
	ft_width(s); 
	ft_putstr_fd(s, 1);
}