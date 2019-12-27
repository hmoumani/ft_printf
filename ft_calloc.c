/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:50:21 by hmoumani          #+#    #+#             */
/*   Updated: 2019/12/23 16:44:55 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*ptr;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (count * size > i)
	{
		((unsigned char*)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
