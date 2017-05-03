/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:24:06 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 23:54:47 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char*)src));
	while (dest[i] && i < size)
		i++;
	slen = i;
	while (src[i - slen] && i < size - 1)
	{
		dest[i] = src[i - slen];
		i++;
	}
	if (slen < size)
		dest[i] = '\0';
	return (slen + ft_strlen((char*)src));
}
