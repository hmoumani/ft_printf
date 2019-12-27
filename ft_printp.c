/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:59:46 by hmoumani          #+#    #+#             */
/*   Updated: 2019/12/24 14:16:31 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(char *s)
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

char	*ft_dectohexa(size_t n)
{
    char 	*hexaDeciNum;
    size_t	i;
	size_t	temp;

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


void	        ft_printp(va_list *args)
{
	size_t			p;
	char			*s;

	p = va_arg(*args, size_t);
	s = ft_dectohexa(p);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(s, 1);
}