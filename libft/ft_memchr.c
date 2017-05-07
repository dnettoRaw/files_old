/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:49:59 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 18:26:56 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (++i - 1 < n)
		if (((unsigned char*)s)[i - 1] == (unsigned char)c)
			return (&((unsigned char*)s)[i - 1]);
	return (NULL);
}
