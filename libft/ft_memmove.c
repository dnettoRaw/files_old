/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 01:45:10 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:13:55 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *str, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)str;
	i = 0;
	if (dst > str)
		while (len--)
			tmp1[len] = tmp2[len];
	else if (dst < str)
		while (++i - 1 < len)
			tmp1[i - 1] = tmp2[i - 1];
	return (tmp1);
}
