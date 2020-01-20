/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:56:08 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/20 15:44:01 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	news = malloc(i + 1);
	news[i] = 0;
	flags.conv = s[i];
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

void	ft_flags(char **s)
{
	while (1)
	{
		if (**s == '+')
			flags.plus = 1;
		else if (**s == '0')
			flags.fill = '0';
		else if (**s == '-' && flags.conv == 'p')
			flags.minus = 1;
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
	flags.haspoint = 1;
	// here 
	ft_flags(&s);
	if (s[i] == '*')
		flags.width = va_arg(*args, int);
	else
		flags.width = ft_atoi(s);
	if (*p == '*')
		flags.prec = va_arg(*args, int);
	else
		flags.prec = ft_atoi(p);
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
		//here
		// ft_flags(&s);
		if (s[i] == '*')
			flags.width = va_arg(*args, int);
		else
		{
			flags.width = ft_atoi(s);
			flags.fill = (s[i] == '0' && flags.width) ? '0' : ' ';
		}
	}
}

int		ft_collect_data(const char *s, int *i, va_list *args)
{
	char *newstr;

	if (!(newstr = ft_get_string(s + *i + 1, i)))
		return (-1);
	ft_manage_data(newstr, args);
	(*i)++;
	free(newstr);
	return (1);
}

