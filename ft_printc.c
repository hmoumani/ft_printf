/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:11:35 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/19 23:50:34 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printc(va_list *args)
{
	char c;

	c = '%';
	if (flags.conv == 'c')
		c = va_arg(*args, int);
	ft_putchar_fd(c, 1);
}
