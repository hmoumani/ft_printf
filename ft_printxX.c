/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:23:26 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/17 20:12:31 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_strrev(char *s)
{
	char temp;
	int i;
	int len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i <= len / 2)
	{
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
		i++;
	}
}

static char	*ft_dectohexax(unsigned int n)
{
    char 	*hexaDeciNum;
    unsigned int	i;
	unsigned int	temp;

	i = 0;
	if (!(hexaDeciNum = ft_calloc(100, sizeof(char))))
		return (NULL);
	hexaDeciNum[0] = '0';
    while(n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexaDeciNum[i] = temp + 48;
		else
			hexaDeciNum[i] = temp + 55;
		n = n / 16;
		if (flags.conv == 'x' || flags.conv == 'p')
			hexaDeciNum[i] = ft_tolower(hexaDeciNum[i]);
		i++;
    }
	ft_strrev(hexaDeciNum);
	return (hexaDeciNum);
}
void            ft_printxX(va_list *args)
{
    size_t  n;
    char    *s;

    n = va_arg(*args, size_t);
    s = ft_dectohexax(n);
    ft_putstr_fd(s, 1);
}