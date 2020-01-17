/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:05:31 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/17 20:17:34 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prints(va_list *args)
{
	char *s;

	s = va_arg(*args, char *);
	if (!s)
		s = ft_strdup("(null)");
	ft_putstr_fd(s, 1);
}