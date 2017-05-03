/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:28:16 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:11:52 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (++i - 1 < n)
		if ((((char*)dst)[i - 1] = ((char*)src)[i - 1]) == c)
			return (((char*)dst) + i);
	return (NULL);
}
