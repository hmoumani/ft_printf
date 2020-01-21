/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:56:08 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/21 03:28:35 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_get_string(const char *s, int *j)
{
	int		i;
	char	*news;

	news = NULL;
	i = 0;
	while (s[i] != 'd' && s[i] != 'c' && s[i] != 's' && s[i] != 'u' && \
	s[i] != 'i' && s[i] != 'x' && s[i] != 'X' && s[i] != 'p' && s[i] != '%')
		i++;
	(*j) = (*j) + i;
	if (!(news = malloc(i + 1)))
		return (NULL);
	news[i] = 0;
	g_flags.conv = s[i];
	i = 0;
	while (s[i] != 'd' && s[i] != 'c' && s[i] != 's' && s[i] != 'u' && \
	s[i] != 'i' && s[i] != 'x' && s[i] != 'X' && s[i] != 'p' && s[i] != '%')
	{
		news[i] = s[i];
		i++;
	}
	news[i] = 0;
	return (news);
}

void	ft_flags(char **s, int cas)
{
	if (cas)
		while (1)
		{
			if (**s == '+')
				g_flags.plus = 1;
			else if (**s == '0')
				g_flags.fill = '0';
			else if (**s == '-' && (g_flags.conv == 'p' || g_flags.conv == 'c'))
				g_flags.minus = 1;
			else if (**s == '-' && g_flags.conv == '%')
				g_flags.minus = 1;
			else
				break ;
			(*s)++;
		}
	else
		while (1)
		{
			if (**s == '-' && *(*s + 1) == '-' && g_flags.conv == 'd')
				g_flags.minus = 1;
			else
				break ;
			(*s)++;
		}
}

void	ft_haspoint(char *s, char *p, va_list *args)
{
	int i;

	i = 0;
	*p = 0;
	p = p + 1;
	g_flags.haspoint = 1;
	ft_flags(&s, 1);
	if (s[i] == '*')
		g_flags.width = va_arg(*args, int);
	else
		g_flags.width = ft_atoi(s);
	if (*p == '*')
		g_flags.prec = va_arg(*args, int);
	else
		g_flags.prec = ft_atoi(p);
}

void	ft_manage_data(char *s, va_list *args)
{
	int		i;
	char	*p;

	i = 0;
	if ((p = ft_strchr(s, '.')))
		ft_haspoint(s, p, args);
	else
	{
		if (s[i] == '*')
			g_flags.width = va_arg(*args, int);
		else
		{
			ft_flags(&s, 0);
			g_flags.width = ft_atoi(s);
			g_flags.fill = (s[i] == '0' && g_flags.width) ? '0' : ' ';
		}
	}
}

int		ft_collect_data(const char *s, int *i, va_list *args)
{
	char *newstr;

	if (!(newstr = ft_get_string(s + *i + 1, i)))
		return (0);
	ft_manage_data(newstr, args);
	(*i)++;
	free(newstr);
	return (1);
}
