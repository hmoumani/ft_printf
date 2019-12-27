/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:08:49 by hmoumani          #+#    #+#             */
/*   Updated: 2019/12/23 17:09:26 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu(va_list *args)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	ft_putnbr_fd(u, 1);
}