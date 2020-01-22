/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:48:39 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/22 01:07:43 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_flags_1(char **s)
{
	while (1)
	{
		if (**s == '+')
			g_flags.plus = 1;
		else if (**s == '0')
			g_flags.fill = '0';
		else if (**s == '-' && (g_flags.conv == 'p' || \
		g_flags.conv == 'c' || g_flags.conv == 'd' || g_flags.conv == 's'))
			g_flags.minus = 1;
		else if (**s == '-' && g_flags.conv == '%')
			g_flags.minus = 1;
		else if (**s == '-' && (*(*s + 1) == '-' || \
		*(*s + 1) == '*') && g_flags.conv == 'd')
			g_flags.minus = 1;
		else
			break ;
		(*s)++;
	}
}

void		ft_flags(char **s, int cas)
{
	if (cas)
		ft_flags_1(s);
	else
		while (1)
		{
			if (**s == '-' && (*(*s + 1) == '-' || \
			*(*s + 1) == '*'))
				g_flags.minus = 1;
			else if (**s == '0' && g_flags.conv == 'd')
				g_flags.fill = '0';
			else
				break ;
			(*s)++;
		}
}
