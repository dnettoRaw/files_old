/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 21:11:15 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/19 22:13:32 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *temp;
	unsigned char *temp1;

	temp = (unsigned char *)dst;
	temp1 = (unsigned char *)src;
	while (n--)
		temp[n] = temp1[n];
	return (dst);
}
