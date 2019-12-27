/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:56:16 by hmoumani          #+#    #+#             */
/*   Updated: 2019/12/23 16:46:21 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_getnumbersize(long n)
{
	int	i;
	int	x;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	x = 1;
	while ((n / x) >= 10)
	{
		x *= 10;
		i++;
	}
	return (i);
}

static	int		ft_getdigit(long n, int pos)
{
	int d;

	d = 1;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (0);
	while (--pos >= 0)
		d *= 10;
	n = n / d;
	return (n % 10);
}

char			*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*p;
	long	nb;

	nb = n;
	i = 0;
	size = ft_getnumbersize(nb);
	p = (char *)ft_calloc(size + 1, sizeof(char));
	if (!p)
		return (p);
	while (i < size)
	{
		p[size - i - 1] = ft_getdigit(nb, i) + 48;
		i++;
	}
	if (nb < 0)
		*p = '-';
	return (p);
}
