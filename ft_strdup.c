/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:06:34 by hmoumani          #+#    #+#             */
/*   Updated: 2020/01/17 20:12:35 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s)
{
	char			*p;
	unsigned	int	i;
	unsigned	int	len;

	i = 0;
	len = ft_strlen(s);
	p = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		*(p + i) = *(s + i);
		i++;
	}
	return (p);
}
